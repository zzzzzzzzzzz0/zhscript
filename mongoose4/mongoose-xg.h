/*
 * mongoose-xg.h
 *
 *  Created on: 2012-10-28
 *      Author: zzzzzzzzzzz
 */

#ifndef MONGOOSE_XG_H_
#define MONGOOSE_XG_H_

//以下在使用mongoose新版时务必对照以保持一致
#include <netinet/in.h>
#include <arpa/inet.h>

// Unified socket address. For IPv6 support, add IPv6 address structure
// in the union u.
union usa {
  struct sockaddr sa;
  struct sockaddr_in sin;
#if defined(USE_IPV6)
  struct sockaddr_in6 sin6;
#endif
};

typedef int SOCKET;

// Describes listening socket, or socket which was accept()-ed by the master
// thread and queued for future handling by the worker thread.
struct socket {
  struct socket *next;  // Linkage
  SOCKET sock;          // Listening socket
  union usa lsa;        // Local socket address
  union usa rsa;        // Remote socket address
  int is_ssl;           // Is socket SSL-ed
};

typedef struct ssl_st SSL;

struct mg_connection {
  struct mg_request_info request_info;
  struct mg_context *ctx;
  SSL *ssl;                   // SSL descriptor
  struct socket client;       // Connected client
  time_t birth_time;          // Time when request was received
  int64_t num_bytes_sent;     // Total bytes sent to client
  int64_t content_len;        // Content-Length header value
  int64_t consumed_content;   // How many bytes of content have been read
  char *buf;                  // Buffer for received data
  char *path_info;            // PATH_INFO part of the URL
  char *log_message;          // Placeholder for the mongoose error log message
  int must_close;             // 1 if connection must be closed
  int buf_size;               // Buffer size
  int request_len;            // Size of the request + headers in a buffer
  int data_len;               // Total size of data in a buffer
  int status_code;            // HTTP reply status code, e.g. 200
  int throttle;               // Throttling, bytes/sec. <= 0 means no throttle
  time_t last_throttle_time;  // Last time throttled data was sent
  int64_t last_throttle_bytes;// Bytes sent this second
};


// Structure used by mg_stat() function. Uses 64 bit file length.
struct mgstat {
  int is_directory;  // Directory marker
  int64_t size;      // File size
  time_t mtime;      // Modification time
};
//以上
#ifdef __cplusplus
extern "C" {
#endif
int convert_uri_to_file_name(struct mg_connection *conn, char *buf,
                                    size_t buf_len, struct mgstat *st);
int mg_stat(const char *path, struct mgstat *stp);
int substitute_index_file(struct mg_connection *conn, char *path,
                                 size_t path_len, struct mgstat *stp);
#ifdef __cplusplus
}
#endif
#endif /* MONGOOSE_XG_H_ */
