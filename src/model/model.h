//
// Created by HaruGakkaP on 2020-01-09.
//

#ifndef ISSUE_ME_MODEL_H
#define ISSUE_ME_MODEL_H

#include <functional>
#include <string>

namespace IssueMe
{
    // 인터페이스 클래스.
    class Model
    {
    public:
        virtual void AddNotice( std::function<void( std::string, const std::string & )> t_callback ) = 0;
    };

}



#endif //ISSUE_ME_MODEL_H
