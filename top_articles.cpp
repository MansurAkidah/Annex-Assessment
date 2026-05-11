#include <vector>
#include <string>
#include <algorithm>
#include <curl/curl.h>
#include <iostream>

using namespace std;
using json = nlohmann::json;

static size_t writeCallback(char* pointer, size_t size, size_t nmemb, string* data){
    data -> append(pointer, size * nmemb);
    return size * nmemb;
}

vector<string> topArticles(int limit){
 CURL* curl = curl_easy_init();

 string response;
 
 if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://jsonmock.hackerrank.com/api/articles");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
 }
 
 json parsedData = json::parse(response);
 
 vector<string> result;

 for (const auto& item : parsedData["data"]) {
    if (result.size() >= limit) break;

    if (!item["title"].is_null()) {
        result.push_back(item["title"]);
    }else if (!item["story_title"].is_null()) {
        result.push_back(item["story_title"]);
    }
    
 }
 
 return result;
}

int main() {
    vector<string> articles = topArticles(5);
    for (const string& name : articles) {
        cout << name << endl;
    }
    return 0;
}