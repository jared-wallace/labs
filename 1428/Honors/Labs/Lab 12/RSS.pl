#!/usr/bin/perl
use strict;
use warnings;
use CGI::Carp qw(fatalsToBrowser carpout);
use CGI;
use XML::RSS::Parser::Lite;
use LWP::Simple;

print "Content-Type: text/html\r\n\r\n";
my @news = ('http://syndication.thedailywtf.com/TheDailyWtf','http://feeds.feedburner.com/cnet/NnTv?format=xml','http://blogs.msdn.com/b/oldnewthing/rss.aspx','http://ericlippert.com/feed/','http://rss.computerworld.com/computerworld/s/feed/topic/18');        
my @articles =();

#initialize my variables. 
my ($rp,$xml,$webTitle,$it,$url,$title,$desc,$time,$time2);

#my $xml = get("http://feeds.feedburner.com/cnet/NnTv?format=xml");

foreach(@news)
{
   #if I put this outside the loop it only ever parses the first element in the array. Why?
   $rp = new XML::RSS::Parser::Lite;

   #test what's in the array

   #gets the xml
   $xml = get($_);
 
   #parses the xml
   $rp->parse($xml);

   #gets the title for the source of news. Can't call functions in hereDocs
   $webTitle = $rp->get('title');

   #get all of the current count of news articles
   for (my $i = 0; $i <$rp->count(); $i++)
   {
      #gets the article with the id $i from the RSS
      $it = $rp->get($i);

      #store all the variables I will need
      #more 1428 escq
      $url= $it->get('url');
      $title = $it->get('title');
      $desc = $it->get('description');
      $time = $it->get('pubDate');
      $time2 = timeConv($it->get('pubDate'));
 
      push(@articles, {url => $url, time=>$time,  time2=>$time2, desc =>$desc, title=>$title, web =>$webTitle});
      
      #Not using this. This is WAY over 1428 students heads.....
      #push(@articles, {url=>$it->get('url'),time=>$it-get('pubDate'),time2=>timeConv($it->get('pubDate')),desc=>$it->get('description'),title=>$it->get('title'),web=>$rp->get('title')});
   }
}


@articles = sort {$b->{time2} <=> $a->{time2}} @articles;

#print the articles
foreach(@articles)
{
  	# print "$_->{title} $_->{time}<br>";
print <<EOF
  <a href = $_->{url}><b>$_->{web}</b> $_->{title}-$_->{time} </a><br>
EOF

}


#stupid ass time conv function
sub timeConv
{
    my ($t) = @_;
    my %month = qw(
    Jan 1  Feb 2  Mar 3  Apr 4  May 5  Jun 6
    Jul 7  Aug 8  Sep 9  Oct 10 Nov 11 Dec 12
    );
    my @time = split(' ', $t);
    my $seconds =0;
    #print "$_<br>";
    $seconds += (($time[3] - 2010)*31536000);
    $seconds += (%month->{$time[2]}*2592000);
    $seconds += ($time[1]*86400);
    my @clock = split(':',$time[4]);
    $seconds += $clock[2];
    $seconds += $clock[1]*60;
    $seconds += $clock[0]*3600;

    #foreach(@time)
    #{
    #    print "$_-";
    #}
    #print "$seconds<br>"; 
   
    return $seconds;
}
