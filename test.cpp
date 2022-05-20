#include "spreadsheet.hpp"
#include "select.hpp"
#include "gtest/gtest.h"

TEST(Select_Contains, NormalInput) {
	     std::stringstream ss;
	     std::string xp;
	     Spreadsheet sheet;

  	    sheet.set_column_names({"First","Last"});
        sheet.add_row({"Ash","Ketchum"});
        sheet.add_row({"Brock","Harrison"});
        sheet.add_row({"Misty","Williams"});
        sheet.add_row({"Gary","Oak"});

        sheet.set_selection(new Select_Contains(&sheet,"Last","Harrison"));
        sheet.print_selection(ss);
        xp = "Brock Harrison \n";

        EXPECT_EQ(ss.str(),xp);

}
TEST(Select_And, basicTest){
        std::stringstream ss;
        std::string expS;

        Spreadsheet sheet;

        sheet.set_column_names({"slimmy"});
        sheet.add_row({"flippity"});
        sheet.add_row({"dippity"});
        sheet.add_row({"hippity"});
        sheet.add_row({"hoppity"});

        sheet.set_selection(new Select_And(new Select_Contains(&sheet,"slimmy","ipp"),new Select_Contains(&sheet,"slimmy","ity")));
        sheet.print_selection(ss);
        expS = "flippity \ndippity \nhippity \n";

        EXPECT_EQ(ss.str(), expS);

}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
