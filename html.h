#ifndef GET_HTML_FILE_H
#define GET_HTML_FILE_H

#include <curlpp/cURLpp.hpp>
#include <curlpp/Types.hpp>
#include <curlpp/Easy.hpp>
#include <vector>
#include <sys/stat.h>
//#include <unistd.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

void get_html_file(const std::string& dir, const std::string& url);

std::vector <unsigned int> parser_file(const std::string& path);

void get_all_data(const std::string &dir);

#endif // GET_HTML_FILE_H
