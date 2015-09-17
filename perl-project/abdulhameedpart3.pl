#!usr/bin/perl
#abdulhameedpart3.pl
#MAT 374 Perl Project Part 3.
#By AbdulHameed Ahmed.

open(FH, "random.txt") or die("Error"); #random.txt contains numbers and charcters.

@array = <FH>; #The @array contains the random.txt.

print "Printing the content in random.txt:\n";
print "@array\n\n\n";

open(FILE, ">outputpart3.txt");

print "Printing the output:\n";
foreach $number (@array) 
{   #Using the substitution operator whatever the digit in the first / / 
	#will be replace with the content in the second / /.
	#The g at the end of the substitution operator replaces all matching patterns.
	$number =~ s/0/zero/g;
	$number =~ s/1/one/g;
	$number =~ s/2/two/g;
	$number =~ s/3/three/g;
	$number =~ s/4/four/g;
	$number =~ s/5/five/g;
	$number =~ s/6/five/g;
	$number =~ s/7/seven/g;
	$number =~ s/8/eight/g;
	$number =~ s/9/nine/g;
	
	print "$number\n"; #Prints whatever $number contains.
	print FILE "$number\n"; #Printing the output of this script to output.txt.
}

close(FH);
close(FILE);

