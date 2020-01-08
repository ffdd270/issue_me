//
// Created by HaruGakkaP on 2020-01-09.
//

#include "document.h"
#include <cassert>

using namespace IssueMe;



//=======================Pages / Public .

PageId Pages::GetPageIndex(int index) const
{
    return m_page_index[index];
}

const std::vector<PageId> &Pages::GetPageIndices() const
{
    return m_page_index;
}

void Pages::addPageIndex(PageId id)
{
    m_page_index.push_back( id );
}

//=======================Document / Public .

void Document::AddNotice(std::function<void(std::string)> t_callback )
{
    m_callback = t_callback;
}

PageId Document::Submit(const std::string & user_id, std::string name, std::string text)
{
    PageId new_id = m_pages.size();
    Page page( new_id, user_id, std::move( name ), std::move( text ) );

    m_pages.push_back( std::move( page ) );
    submitToCache( new_id, user_id );

    return new_id;
}

const Pages & Document::GetByUserId(const std::string& user_id) const
{
    auto iter = m_cache_by_user_pages.find( user_id );

    if( iter == m_cache_by_user_pages.end() )
    {
        assert(  iter != m_cache_by_user_pages.end() );
    }

    return iter->second;
}

const Page & Document::GetByPageId(PageId id) const
{
    assert( id >= m_pages.size() );

    return m_pages[id];
}

//=======================Document / Private .

void Document::submitToCache(PageId id, const std::string & user_id)
{
    auto iter = m_cache_by_user_pages.find(user_id);

    if (iter == m_cache_by_user_pages.end())
    {
        Pages pages;
        m_cache_by_user_pages.insert( std::pair<std::string, Pages>( user_id, pages )  );
    }

    auto & pages = m_cache_by_user_pages[user_id];
    pages.addPageIndex(id);
}

