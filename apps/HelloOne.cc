
// #include "../mongoose.h"
#include "../mongoose.c"

// Connection event handler function
static void fn(struct mg_connection *c, int ev, void *ev_data) {
  if (ev == MG_EV_HTTP_MSG) {  // New HTTP request received
    struct mg_http_message *hm = (struct mg_http_message *) ev_data;  // Parsed HTTP request
    if (mg_match(hm->uri, mg_str("/api/hello"), NULL)) {              // REST API call?
      mg_http_reply(c, 200, "", "{%m:%d}\n", MG_ESC("status"), 1);    // Yes. Respond JSON
    } else {
      struct mg_http_serve_opts opts = {".", NULL, NULL, NULL, NULL};  // For all other URLs,
      mg_http_serve_dir(c, hm, &opts);                     // Serve static files
    }
  }
}

int main() {
  struct mg_mgr mgr;  // Mongoose event manager. Holds all connections
  mg_mgr_init(&mgr);  // Initialise event manager
  mg_http_listen(&mgr, "http://0.0.0.0:8000", (mg_event_handler_t)fn, NULL);  // Setup listener
  for (;;) {
    mg_mgr_poll(&mgr, 1000);  // Infinite event loop
  }
  return 0;
}

// http://127.0.0.1:8000
// http://127.0.0.1:8000/api/hello
