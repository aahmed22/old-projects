#!usr/bin/perl
#abdulhameedpart1.pl
#MAT 374 Perl Project Part 1.
#By AbdulHameed Ahmed.

open (FH, "solar.txt") or die ("Error");

@array = <FH>; #This array contains the solar.txt.

#Question1 of Part1.
print "1)Print all records that do not list a discoverer in the eigth field.\n\n";
#Using the foreach loop we can scan every element inside the @array.
foreach $record(@array) 
{
	if($record =~ m/Voyager2/) #Using the match operator and the =~ operator we want to compare
	{                          #if the string inside record has the work Voyager2.
		print "$record\n";     #If the condition is true it will print all strings containing Voyager2.
	}
	
	if($record =~ m/- -/)      #Using the match operator if the string contains a - - then the 
	{						   #condition is true, thus print string containing - - .
		print "$record\n";
	}
}

@array2 = @array;  #Copying the original array inside a second array.

#Question2 of Part1.
print "\n\n2)Print every record omitting  the second field.\n";

foreach $record (@array2)
{
	#Using the split function we are seperating every word inside the string that contains a space
	#and storing it inside @A.
	@A = split(' ', $record); 
	@B = splice(@A, 1, 1); #After seperating the words, we use the splice function to remove the
						   #second element inside @A.
	
	print "\n@A\n";  #We print the @A that has the second element omitted.
}

#Question3 of Part1.
print "\n\n3)Print the records for satellites that have negative orbitals\n\n";

foreach $record (@array)
{
	if($record =~ /-\d/)   # \d represents any digit from 0-9. Placing the - before \d 
	{					   #means looking for negative digits from 0-9.
		print "$record\n"; #We print the record that have negative orbitals.
	}
}

#Question4 of Part1.
print "\n\n4)Print the data for the objects discovered by the Voyager2 space probe.\n\n";

foreach $record (@array)
{
	if($record =~ /Voyager2/) #Using the match operator to see if there are any strings that
	{						  #have Voyager2.
		print "$record\n";    #If the condition is true, it will print the string that has Voyager2.
	}
}

#Question5 of Part1.
print "\n\n5)Print each record with the orbital period given in seconds rather than days.\n\n";

foreach $orbital (@array)
{   #Using the split function to split the elements inside @array. 
	#The fourth index contains the orbital in days. We set an if condition.
	#Some records contain negative orbitals as days others do not specify what is the orbital in days.
	#So the if-condition states that if the fourth index does not equal to - or ? then execute the following
	#statement. Reading form left to right: 24 represents how many hours are in a day. 60 represents how 
	#many minutes are in an hour. The second 60 represents how many seconds are in a minute.
	#The formula to convert days into seconds is number_of_days * 24 * 60 * 60 = number_of_seconds.
	@A = split(' ', $orbital);
	if(($A[4] != "-") || ($A[4] != "?"))
	{
		$A[4] *= 24 * 60 * 60;
	}
	
	print "\n@A\n";
}

close(FH); 
