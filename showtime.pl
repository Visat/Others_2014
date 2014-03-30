use LWP::UserAgent;
use Encode qw/encode decode/;

$page = <STDIN>;
$ua = LWP::UserAgent->new();
$res = $ua->get($page);
my $pageContent = $res->content();

if($res->is_success){
#   print encode("big5", decode("utf-8", $res->content()) );
   $pageContent = encode("big5", decode("utf-8", $pageContent) );
   foreach($pageContent){
      s/<(?:[^>'"]*|(['"]).*?\1)*>//gs;
      s/^\s*\n//mg;
      print $pageContent;
   }

}
else{
   print $res->status_line,"\n";
}

exit

