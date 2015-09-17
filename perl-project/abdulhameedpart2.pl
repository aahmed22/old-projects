#!usr/bin/perl
#abdulhameedpart2.pl
#MAT 374 Perl Project Part 2.
#By AbdulHameed Ahmed.

open(FH, "electricity.txt") or die("Error");
open(FILE, ">outputpart2.txt");

@array = <FH>; #Storing the electricity.txt inside of an array.

foreach $symbols (@array) 
{   #Using the substution operator to replace all symbols with blank spaces.
	$symbols =~ s/\(/ /g;  #Substitute left parentheses with blank space.
	$symbols =~ s/\)/ /g;  #Substitute right parentheses with blank space.
	$symbols =~ s/\[/ /g;  #Substitute left brace with blank space.
	$symbols =~ s/\]/ /g;  #Substitute right brace with blank space.
	$symbols =~ s/[",':~\!\?\-\.\d\/]/ /g; #Substitute multiple symbols with blank space. 
	#In order to substitute MetaCharacters need to use \ before the symbol you want to replace.
	push(@array2, split(' ', $symbols)); #Using the split function to seprate the remaining elements
	#and storing it in @array2, then adding the remaining content at the end.
}

#Using the sort functions to sort the elements in @array2 in alphabetical order.
@sorted_array = sort{ lc($a) cmp lc($b) } @array2; 

#Question1 of Part2
print "1)Alphabetically (Ignoring Capitalization):\n";
print FILE "1)Alphabetically (Ignoring Capitalization):\n";											   
foreach $letter_word(@sorted_array) 
{
	print "$letter_word\n"; #Prints the cotent inside $letter_word during the iteration.
	print FILE "$letter_word\n"; #Print the output of this program to outputpart2.txt.
}


#Question2 of Part2
print "\n\n2)Alphabetically placing upper case words before lower case words:\n";
print FILE "\n\n2)Alphabetically placing upper case words before lower case words:\n";
#Created @sorted2 to sort the first sorted_array this time not only sorting it
#alphabetically but also placing upper case words before lower case words.
@sorted2 = sort{ $a cmp $b } @sorted_array; 

foreach $word (@sorted2) 
{
	print "$word\n"; #Printing the content inside $word.
	print FILE "$word\n"; #Printing the output of this script to outputpart2.txt.
}

#Question3 of Part2
print "\n\n3)By Frequency, from high to low (any order for equal frequency):\n";
print "Frequency\tWord\n";
print FILE "\n\n3)By Frequency, from high to low (any order for equal frequency):\n";
print FILE "Frequency\tWord\n";

foreach $x(@array2)
{
	$freq{$x}++; #Keeps count of how many words are being passed from @array2.
}

#<=> operator to compare the frequency between the words whether or not one's frequency was greater
#than the other. Finally we sort the frequency numerically from high to low.
foreach $y(sort {$freq{$b} <=> $freq{$a}} keys %freq)
{
	print "$freq{$y}\t\t$y\n"; #Prints the frequency as well as the word.
	print FILE "$freq{$y}\t\t$y\n"; #Prints the content of $freq and $t inside the outputpart2.txt.
}

#Question4 of Part2
print "\n\n4)By Frequency, with alphabetical order for words with the same frequency:\n";
print "Frequency\tWord\n";
print FILE "\n\n4)By Frequency, with alphabetical order for words with the same frequency:\n";
print FILE "Frequency\tWord\n";

foreach $i(@array2)
{
	$freq2{$i}++; #Keeps count of how many words are being passed from @array2.
}

#<=> operator to compare the frequency between the words and also sort the words that have the 
#same frequency from high to low alphabetically.
foreach $j(sort {$freq2{$b} <=> $freq2{$a} or lc("$a") cmp lc("$b")} keys %freq2)
{
	print "$freq2{$j}\t\t$j\n"; #Prints the frequency as well as the word.
	print FILE "$freq2{$j}\t\t$j\n"; #Prints the content of $freq2 and $j inside the outputpart2.txt.
}

close(FH);
close(FILE);
		
