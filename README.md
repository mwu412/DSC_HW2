
<!DOCTYPE html>


<html lang="en">
  <head>
    <meta charset="UTF-8">
    
<title>Problem 11859</title>

    <!-- bootstrap, bootwatch CSS -->
    
    <link rel="stylesheet" href="/static/bootswatch/cerulean/bootstrap.min.css">
    
    <!-- Magnific Popup core CSS -->
    <link rel="stylesheet" href=/static/magnific-popup/dist/magnific-popup.css>
    <link rel="stylesheet" href=/static/css/index.css media="screen">
    <link rel="stylesheet" href=/static/css/mfp-fade.css media="screen">
    <script src=/static/jquery/dist/jquery.min.js></script>
  </head>
  <body>
    <!-- navbar -->
    <nav class="navbar navbar-inverse newbar" >
      <div class="container-fluid">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="/">NTHU Online Judge</a>
        </div>
        <div class="collapse navbar-collapse">
          <ul class="nav navbar-nav">
            <li class="nav-text"><a href="/contest/">Contest</a></li>
            <li class="nav-text"><a href="/problem/">Problem</a></li>
            <li class="nav-text"><a href="/users/submit/">Submit</a></li>
            <li class="nav-text"><a href="/status/?username=DSC103033210">Status</a></li>
            <!--li class="nav-text"><a href="/group/list/">Group</a></li-->
            <!--
            <li class="dropdown nav-text">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown"
                 role="button" aria-expanded="false">User
                 <span class="caret"></span>
               </a>
              <ul class="dropdown-menu" role="menu">
                <li><a href="#">User List</a></li>
                <li><a href="#">User Rank</a></li>
              </ul>
            </li>
            -->
            <li class="nav-text">
              <form class="navbar-form">
                <div class="form-group">
                  <input id="globalNavigation" type="text" class="form-control" placeholder="Search Site">
                </div>
              </form>
            </li>
          </ul>
          <ul class="nav navbar-nav navbar-right">
            
            <li>
              <a href=/users/notification/ id="notification">
                
                <img src=/static/images/bell_blue.png  id="notification_img"
                     title="You have 30 unread notifications."/>
                <div id="notification_circle" class="center">
                  <b id="number">
                    
                      30
                    
                  </b>
                </div>
                
              </a>
            </li>
            
            
            <li class="nav-text-auth">
              <a href="/users/profile/DSC103033210">
                <i id="name-text">DSC103033210</i>
              </a>
            </li>
            <li class="nav-text-auth"><a href="/users/logout/">Logout</a></li>
            
          </ul>
        </div>
      </div>
    </nav>

    <!-- wrap all page elements to div -->
    <div class="wrap-body container-fluid">
      

      
<div class="container" id="Body">
  
<div class="pname_block panel">
  <div class="left">
    <div class="pname">
      <h2>11859 - infix maze &nbsp;&nbsp;
        
      </h2>
    </div>
  </div>
  <div class="right">
    <div class="problem-option">
      <a href="/status/?pid=11859">Status</a> &nbsp;|&nbsp;
      <!-- <a>Printable </a> &nbsp;|&nbsp; -->
      <!-- <a>Rank</a> &nbsp;|&nbsp; -->
      <a data-toggle='modal' data-target='#limit_11859'>Limits</a>
      
        <a class="btn btn-primary" href="/users/submit/11859">Submit</a>
      
    </div>
  </div>
</div>

<div class='modal fade' id='limit_11859'>
  <div class='modal-dialog modal-sm'>
    <div class='modal-content'>
      <div class='modal-header'>
        <button type='button' class='close' data-dismiss='modal'>
          <span aria-hidden='true'>&times;</span>
          <span class='sr-only'>Close</span>
        </button>
        <h4 class='modal-title'>Limits</h4>
      </div>
      <div class='modal-body'>
        <table class='table'>
          <tbody>
            <tr>
              <td></td>
              <th>Time</th>
              <th>Memory</th>
              
              <tr>
                <th>Case 1</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
              <tr>
                <th>Case 2</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
              <tr>
                <th>Case 3</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
              <tr>
                <th>Case 4</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
              <tr>
                <th>Case 5</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
              <tr>
                <th>Case 6</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
              <tr>
                <th>Case 7</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
              <tr>
                <th>Case 8</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
              <tr>
                <th>Case 9</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
              <tr>
                <th>Case 10</th>
                <td>1 sec</td>
                <td>32 MB</td>
              </tr>
              
          </tbody>
        </table>
      </div>
    </div>
  </div>
</div>

<div style="width:75%; float:left">
  <h3>Description</h3>
  <div style="margin-left:.19in;">
<p>Determine whether a matrix contains at least a legal infix expression which need to be from the top-left corner to the bottom-right corner. If yes, convert it based on the postfix notation.</p>

<p>There are some rules&nbsp;to be followed.&nbsp;</p>

<ul>
	<li>Each cell can be reached by&nbsp;four directions(up, down, right, left).</li>
	<li>Matrices are consisted of 1~9, +,-,*,/, (, )</li>
	<li>Each cell can be visited at most one time.</li>
	<li>The priority directions are: down&gt;right&gt;left&gt;up.</li>
	<li>No negative number. EX: - 5 + 3 is illegal.</li>
</ul>
</div>

<div style="margin-left:.19in;">&nbsp;</div>

<div style="margin-left:.19in;"><img alt="" src="/media/uploads/2018/03/28/capture.PNG" style="height:322px; width:372px" /></div>

  <h3>Input</h3>
  <p>First line is total number of matrices.</p>

<p>Second and third line are matrix width nad height.</p>

<p>Width and height &lt;100.</p>

<p>Following lines are matrix.</p>

  <h3>Output</h3>
  <p>Repeat all inputs.<br />
For matrix, there is a white space after every elements.</p>

<p>If there is a legal infix expression from the top-left corner to the bottom-right corner,&nbsp; output<br />
Yes<br />
infix expression ( there is a white space after every elements.)<br />
postfix expression&nbsp;( there is a white space after every elements.)</p>

<p>If No, output<br />
No</p>

  <h3>Sample Input&nbsp;&nbsp;<a class='btn btn-primary downloadSampleInputButton' pid='11859'>Download</a></h3>
  <div class='panel-body'>
    <textarea id='11859_sampleIn' class='panel-body sampleIO' readonly>1
3
3
1 5 4 
+ - * 
+ 6 8 </textarea>
  </div>
  <h3>Sample Output&nbsp;&nbsp;<a class='btn btn-primary downloadSampleOutputButton' pid='11859'>Download</a></h3>
  <div class='panel-body'>
    <textarea id='11859_sampleOut' class='panel-body sampleIO' readonly>1
3
3
1 5 4 
+ - * 
+ 6 8 
Yes
15 - 68 
15 68 - 
</textarea>
  </div>
  
  
  
  <h3>Tags</h3>
    <div id='tags' style='float:left;width:60%'>
      
        
      
    </div>
    
      <form id='addTag'>
        <input type='hidden' name='csrfmiddlewaretoken' value='XmgNZ3ux73FnysHzFjIPxn3THuMhyXYs' />
        <div class='input-group'>
          <input class="form-control autocomplete vTextField autocomplete-light-text-widget autocomplete vTextField autocomplete-light-text-widget" data-autocomplete-choice-selector="[data-value]" data-autocomplete-minimum-characters="1" data-autocomplete-url="/autocomplete/TagAutocomplete/" data-widget-bootstrap="text" id="id_tag_name" maxlength="20" name="tag_name" placeholder="" type="text" />
          <span class="input-group-btn">
	    <button id='addTagButton' class="btn btn-default" type="button">
	      Add Tag
	    </button>
          </span>
        </div>
      </form>
    
  

  <br>
  <br>
  <br>
  <h4>
    <a onclick="alert('Discuss not open yet')">Discuss</a>
  </h4>
  <br>
  <br>
  <br>
</div>
<script>
var pid = 11859;
</script>
<script src="/static/problem/js/problem.js"></script>


</div>

    </div>

    <!-- footer -->
    <footer>
      <div class="navbar navbar-inverse navbar-fixed-bottom sticky-footer container-fluid">
        <div class="navbar-collapse collapse">
          <p class="navbar-text col-lg-4">Contact us: nthucsoj@gmail.com</p>
          <p class="navbar-text col-lg-6">© NTHU Online Judge 2015, Templates are from Bootswatch Project</p>
          <p id="time" class="navbar-text">2018/05/02 16:25:57</p>
        </div>
      </div>
    </footer>

    <!-- JS -->
    <script src=/static/bootstrap/dist/js/bootstrap.min.js></script>
    <script src=/static/js/function.js></script>
    <script src=/static/magnific-popup/dist/jquery.magnific-popup.min.js></script>
    

<script type="text/javascript">
jQuery(function($) {
function getCookie(name) {
    var cookieValue = null;
    if (document.cookie && document.cookie != '') {
        var cookies = document.cookie.split(';');
        for (var i = 0; i < cookies.length; i++) {
            var cookie = jQuery.trim(cookies[i]);
            // Does this cookie string begin with the name we want?
            if (cookie.substring(0, name.length + 1) == (name + '=')) {
                cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
                break;
            }
        }
    }
    return cookieValue;
}
function csrfSafeMethod(method) {
    // these HTTP methods do not require CSRF protection
    return (/^(GET|HEAD|OPTIONS|TRACE)$/.test(method));
}
function sameOrigin(url) {
    // test that a given url is a same-origin URL
    // url could be relative or scheme relative or absolute
    var host = document.location.host; // host + port
    var protocol = document.location.protocol;
    var sr_origin = '//' + host;
    var origin = protocol + sr_origin;
    // Allow absolute or scheme relative URLs to same origin
    return (url == origin || url.slice(0, origin.length + 1) == origin + '/') ||
        (url == sr_origin || url.slice(0, sr_origin.length + 1) == sr_origin + '/') ||
        // or any other URL that isn't scheme relative or absolute i.e relative.
        !(/^(\/\/|http:|https:).*/.test(url));
}
$.ajaxSetup({
    beforeSend: function(xhr, settings) {
        if (!csrfSafeMethod(settings.type) && sameOrigin(settings.url)) {
            // Send the token to same-origin, relative URLs only.
            // Send the token only if the method warrants CSRF protection
            // Using the CSRFToken value acquired earlier
            xhr.setRequestHeader("X-CSRFToken", getCookie('csrftoken'));
        }
    }
});
});
</script>


<script type="text/javascript" src="/static/autocomplete_light/django_admin.js"></script>
<script type="text/javascript" src="/static/autocomplete_light/autocomplete.js"></script>
<script type="text/javascript" src="/static/autocomplete_light/widget.js"></script>
<script type="text/javascript" src="/static/autocomplete_light/addanother.js"></script>
<script type="text/javascript" src="/static/autocomplete_light/text_widget.js"></script>
<script type="text/javascript" src="/static/autocomplete_light/remote.js"></script>
<link rel="stylesheet" type="text/css" href="/static/autocomplete_light/style.css" />

    <script src=/static/js/popup-setting.js></script>
    <script src=/static/js/base.js></script>
    <script src=/static/js/clock.js></script>
    
  <link rel="stylesheet" href="/static/problem/css/problem.css">

  </body>
</html>
