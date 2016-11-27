#include "html.h"
#include <string>
#include <fstream>
#include <ctype.h>
#include <vector>

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

void get_html_file(const std::string &dir, const std::string &url)
{
    long http_code = 200;

    struct stat info;
    if( stat( dir.c_str(), &info ) != 0 )
    {
        std::cout << "Make directory " <<  dir.c_str() << std::endl;
        mkdir(dir.c_str(), 0700);
    }
    else
    {
        system(("exec rm -r " + dir + "/*").c_str());
    }
    unsigned int num_circulation = 1;
    while (true)
    {
        std::string num_str = std::to_string(num_circulation);

        CURL *curl_handle;
        FILE *file;

        curl_global_init(CURL_GLOBAL_ALL);

        /* init the curl session */
        curl_handle = curl_easy_init();

        /* set URL to get */
        curl_easy_setopt(curl_handle, CURLOPT_URL, (url + num_str).c_str());

        /* no progress meter please */
        curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

        /* send all data to this function  */
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);

        if (http_code == 200)
        {
            /* open the file */
            file = fopen((dir +  '/' + num_str).c_str(),"w");
            if (file == NULL) {
                curl_easy_cleanup(curl_handle);
            }
        }

        /* we want the headers to this file handle */
        curl_easy_setopt(curl_handle,   CURLOPT_WRITEDATA, file);

        /*
     * Notice here that if you want the actual data sent anywhere else but
     * stdout, you should consider using the CURLOPT_WRITEDATA option.  */

        /* get it! */
        curl_easy_perform(curl_handle);

        /*Check for page found */
        curl_easy_getinfo (curl_handle, CURLINFO_RESPONSE_CODE, &http_code);
        if (http_code == 200)
        {
            //Succeed
            std::cout << "Get page: " << url + num_str << std::endl;
        }
        else
        {
            //Failed
            break;
        }

        /* close the file */
        fclose(file);

        /* cleanup curl stuff */
        curl_easy_cleanup(curl_handle);
        num_circulation++;
    }
}




void parser_files(const std::string &dir)
{
    const char * filename = (dir +  '/' + '1').c_str();
    std::ifstream fin(filename);
    std::string line;
    std::vector <unsigned int> numbers;
    while (std::getline(fin, line))
        if (line.find("class=\"number\"") != std::string::npos)
        {
            std::cout <<line << std::endl;
            std::string tmp;
            for (size_t i=0; i < line.size(); i++)
            {
                if (isdigit(line[i]))
                    tmp += line[i];
            }
            numbers.push_back(std::stoi(tmp));
        }
    for (size_t i=0; i < numbers.size(); i++)
        std::cout << numbers[i] << ' ';

    std::cout << std::endl;
    fin.close();
}
