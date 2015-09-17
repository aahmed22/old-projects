//Exercise2 from slide chapter 9_3.
//By AbdulHameed Ahmed.
class Date
{
private: //Declared three data members.
	int month;
	int day;
	int year;
public:
	Date(); //default constructor.
	Date(int, int, int); //constructor for assigning values for the data members.
	void setmonth(int); //funtion to set the month.
	void setday(int); //function to set the day.
	void setyear(int); //function to set the year.
	void displayDate(); //function display the entire date.
	int getmonth(); //function to get the month.
	int getday(); //function to get the day.
	int getyear(); //function to get the year.
};
