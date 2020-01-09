#include <test/catch.h>
#include <iostream>


#include "model/document.h"


TEST_CASE( "Test Document", "[classic]" )
{
    std::string user_id = "HaruGakka#323";
    std::string response;
    std::string text;
    IssueMe::Document document;


    document.AddNotice( [&response, &text](std::string event, const std::string & t_text)
    {
        std::cout << " EVENT : " << event << std::endl;
        std::cout << " text : " << t_text << std::endl;

        text = t_text;
        response = std::move( event );
    });


    SECTION( "Submit" )
    {
        document.Submit(user_id,  "What Is The C++?", "Yah! We On Ruby!");

        REQUIRE( response == "Submit");
        REQUIRE( text == "Yah! We On Ruby!" );
    }

	SECTION( "Submit And Get Page")
    {
	    IssueMe::PageId page_id = document.Submit(user_id, "RUBY RUBY", "Yah! We On Ruby!");
    	
		auto page = document.GetByPageId(page_id);

		REQUIRE(text == page.text);
		REQUIRE(user_id == page.user_id);
		REQUIRE(page_id == page.page_id);
		REQUIRE("RUBY RUBY" == page.name);
    }
}