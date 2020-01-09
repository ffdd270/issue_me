//
// Created by HaruGakkaP on 2020-01-09.
//

#ifndef ISSUE_ME_DOCUMENT_H
#define ISSUE_ME_DOCUMENT_H

#include "model.h"

#include <utility>
#include <vector>
#include <unordered_map>

/*
 * Get == 오류 보장 없음.
 * Find == 오류 보장 해줌. bool이나 index로 리턴.
 */

namespace IssueMe
{
    using PageId = long long;

    struct Page
    {
        const PageId page_id;
        const std::string user_id;

        std::string name;
        std::string text;

        Page(PageId t_page_id , std::string t_user_id) : page_id( t_page_id ), user_id(std::move( t_user_id ))
        {

        }

        Page(PageId t_page_id , std::string t_user_id, std::string t_name, std::string t_text) :
            page_id( t_page_id ), user_id(std::move( t_user_id )), name(std::move( t_name )), text(std::move( t_text ))
        {

        }
    };

    class Pages
    {
    public:
        friend class Document;

        PageId GetPageIndex(int index) const;
        const std::vector<PageId> & GetPageIndices( ) const;
    private:
        void addPageIndex(PageId id);

    private:
        std::vector<long long> m_page_index;
    };

    class Document : public Model
    {
    public: //con;
        Document();
    public: //Model Interface
        void AddNotice( std::function<void( std::string, const std::string &)> t_callback ) override;
    public:
        PageId Submit(const std::string & user_id, std::string name, std::string text );

        const Pages & GetByUserId( const std::string& user_id ) const;
        const Page & GetByPageId( PageId id ) const;
    private:
        void submitToCache( PageId id, const std::string & user_id );
    private:
        std::function< void(std::string, const std::string &) > m_callback;

        std::vector<Page> m_pages;
        std::unordered_map<std::string, Pages> m_cache_by_user_pages;
    };

}


#endif //ISSUE_ME_DOCUMENT_H
