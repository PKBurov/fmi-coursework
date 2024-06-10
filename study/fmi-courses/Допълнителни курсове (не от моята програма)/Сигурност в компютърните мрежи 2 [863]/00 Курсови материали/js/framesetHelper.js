// This method and varialbe is used to tell the content level frame what context it is in (Personalized Feedback, Curriculum, etc...)
var topName = "";
function getTopName() {
    if (topName == "" && isTop())
    {
        //alert("topName is not set");
    }
    else if (topName == "")
    {
        topName = parent.getTopName();
    }
    return new String(topName);
}

// This method is used to determine if you are currently 
// in the top window
function isTop()
{
    return (window.self == window.top);
}

//I believe this code is dead.
function prevPage() {
    if (isTop()) {
        prevPage();
    }
    else {
        parent.prevPage();
    }
}

// This method is used to generate path info after the docRoot.
function computeGUIDPath(oid, chapOID, rloOID, rioOID)
{	
    var result = "";
    var nbparams = "CHAPID=" + chapOID + "/RLOID=" + rloOID + "/RIOID=" + rioOID;
    dash = oid.indexOf('-');
    sub1 = oid.substring(0,dash);
    sub2 = oid.substring(dash+1);
    result = nbparams +"/"+ sub1 +"/"+ sub2 +"/";

    return result;
}

// This method is called from the changeContent() method in feedbackframest when regular content is being navigated to.
function writePageFrameset(contentType, cvOID, chapOID, rloOID, rioOID, docRoot)
{
    var frameContent = "";
    if (contentType == 'feedbackframeset' || contentType == 'stynamicfeedback' || contentType == 'staticfeedback') {
        frameContent = '<html>';
        frameContent += '<head>';
        frameContent += '<meta http-equiv="Content-Type" content="text/html; charset=utf-8">';
        frameContent += '<title>Cisco Networking Academy Program - Personalized Feedback Report</title>';
        frameContent += '</head>';
        frameContent += '<body>';

        var text = getPFReport();
        var pfTree = getPFTree();
        frameContent += text;
        frameContent += '</body>';
        frameContent += '</html>';
        feedback_frame.document.open();
        feedback_frame.document.write(frameContent);
        feedback_frame.document.close();
        /*
				if(contentType == 'feedbackframeset' || contentType == 'dynamicfeedback'){
		    	pfTree.targetWindow = window.open(docRoot + computeGUIDPath(cvOID, chapOID, rloOID, rioOID) + 'dynamicfeedback.html','chapterframeset',"width="+(screen.width-1)+",height="+(screen.height-97)+",top=0,left=0,resizable=yes,scrollbars=yes,toolbar=no,menubar=no,status=no");
				}
				else if (contentType == 'stynamicfeedback'){
		    	pfTree.targetWindow = window.open(docRoot + computeGUIDPath(cvOID, chapOID, rloOID, rioOID) + 'chapterframeset.html','chapterframeset',"width="+(screen.width-1)+",height="+(screen.height-97)+",top=0,left=0,resizable=yes,scrollbars=yes,toolbar=no,menubar=no,status=no");
				}
				else{
        	pfTree.targetWindow = window.open(docRoot + computeGUIDPath(cvOID, null, null, null) + 'staticfeedback.html','chapterframeset',"width="+(screen.width-1)+",height="+(screen.height-97)+",top=0,left=0,resizable=yes,scrollbars=yes,toolbar=no,menubar=no,status=no");
				}
				*/
    }
    else {
        var navPath = "";
        var navFile = "";

        // this conditional is used to set navigation state for quiz and
        // review pages when they are launched from the index
        // in normal curriculum
        if (contentType != 'normal' && contentType != 'contentresource')
        {
            top.currentSupport = 1;
            top.firstSupportPage = rioOID; 
            top.prevPage = rioOID;
            top.contentResourceID = "";
        }

        frameContent = '<html>';
        frameContent += '<head>';
        frameContent += '<meta http-equiv="Content-Type" content="text/html; charset=utf-8">';
        frameContent += '<title>Cisco Networking Academy Program - NEW</title>';
        frameContent += '</head>';
        frameContent += '<frameset cols="490,301" framespacing="0" border="0" frameborder="0" onload="window.focus()">';
        frameContent += '<frameset rows="100%,57">';
        frameContent += '<frame name="media_frame" scrolling="no" marginwidth="0" marginheight="0" src="' + docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID) + 'media.html"';
        frameContent += '</frame>';

        // we need a conditional here for the list frame.
        
		//alert(navPath);

        navPath = docRoot + computeGUIDPath(cvOID, chapOID, "null", "null");
        navFile = 'chapterlist.html';

        frameContent += '<frame name="list_frame" scrolling="no" marginwidth="0" marginheight="0" noresize="true" target="main_frame" src="' + navPath + navFile + '">';
        frameContent += '</frame>';
        frameContent += '</frameset>';
        frameContent += '<frameset rows="100%,57">';
        frameContent += '<frame name="content_frame" scrolling="yes" marginwidth="0" marginheight="0" target="_self" src="' + docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID) + 'content.html">';
        frameContent += '</frame>';
        
        navPath = docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID);
        
        if (contentType == 'quiz')
        {
            navFile = 'quiznav.html';
        }
        else if (contentType == 'review')
        {
            navFile = 'reviewnav.html';
        }
        else if (contentType == 'contentresource')
        {
            navFile = 'contentresourcenav.html';
        }
        else
        {
            navFile = 'navigation.html';
        }
		//alert(navPath);

        frameContent += '<frame name="navigation_frame" scrolling="no" marginwidth="0" marginheight="0" noresize="true" target="_self" src="' + navPath + navFile + '">';
        frameContent += '</frame>';
        frameContent += '</frameset>';
        frameContent += '<noframes>';
        frameContent += '<body>';
        frameContent += '<p>This page uses frames, but your browser doesn\'t support them.</p>';
        frameContent += '</noframes>';
        frameContent += '</frameset>';
        frameContent += '</html>';

        main_frame.document.open();
        main_frame.document.write(frameContent);
        main_frame.document.close();
    }
}

// This method is called from the changeContent() method in feedbackframeset, also directly from resourceframeset.
function writeResourceFrameset(docRoot,rioOID,rloOID,chapOID,cvOID,chapType,contextAuthor)
{
    var frameContent = "";
    var navPath = "";
    var navFile = "";
    
    if (contentType == 'feedbackframeset')
    {
        main_frame.location.href = docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID) + 'pageframeset.html';
    }
    else
    {

        frameContent = '<html>';
        frameContent += '<head>';
        frameContent += '<meta http-equiv="Content-Type" content="text/html; charset=utf-8">';
        frameContent += '<title>Cisco Networking Academy Program - NEW</title>';
        frameContent += '</head>';
        frameContent += '<frameset cols="490,301" framespacing="0" border="0" frameborder="0" onload="window.focus()">';
        frameContent += '<frameset rows="100%,57">';
        frameContent += '<frame name="media_frame" scrolling="no" marginwidth="0" marginheight="0" src="' + docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID) + 'media.html"';
        frameContent += '</frame>';

        // we need a conditional here for the list frame.
        

        navPath = docRoot + computeGUIDPath(cvOID, chapOID, "null", "null");
        navFile = 'chapterlist.html';

        frameContent += '<frame name="list_frame" scrolling="no" marginwidth="0" marginheight="0" noresize="true" target="main_frame" src="' + navPath + navFile + '">';
        frameContent += '</frame>';
        frameContent += '</frameset>';
        frameContent += '<frameset rows="100%,57">';
        frameContent += '<frame name="content_frame" scrolling="yes" marginwidth="0" marginheight="0" target="_self" src="' + docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID) + 'content.html">';
        frameContent += '</frame>';
        
        navPath = docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID);
        
        if (contentType == 'quiz')
        {
            navFile = 'quiznav.html';
        }
        else if (contentType == 'review')
        {
            navFile = 'reviewnav.html';
        }
        else
        {
            navFile = 'navigation.html';
        }

        frameContent += '<frame name="navigation_frame" scrolling="no" marginwidth="0" marginheight="0" noresize="true" target="_self" src="' + navPath + navFile + '">';
        frameContent += '</frame>';
        frameContent += '</frameset>';
        frameContent += '<noframes>';
        frameContent += '<body>';
        frameContent += '<p>This page uses frames, but your browser doesn\'t support them.</p>';
        frameContent += '</noframes>';
        frameContent += '</frameset>';
        frameContent += '</html>';

        main_frame.document.open();
        main_frame.document.write(frameContent);
        main_frame.document.close();

    }
}

// This method is called from the changeContent() method in feedbackframeset, also directly from resourceframeset.
function writeResourceFrameset(docRoot,rioOID,rloOID,chapOID,cvOID,chapType,contextAuthor)
{

    var frameContent = "";
    var navPath = "";
    var navFile = "";

    top.currentSupport = 1;
    top.firstSupportPage = rioOID; 
    top.prevPage = rioOID;
    top.contentResourceID = rioOID;

    frameContent += '<frameset rows="100%,57" framespacing="0" border="0" frameborder="0">';
    frameContent += '<frame name="Rcontent_frame" scrolling="auto" marginwidth="0" marginheight="0" noresize="true" src="' + docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID) + 'resourcecontent.html">';
    frameContent += '</frame>';
    frameContent += '<frameset cols="490,301">';
    

    if (chapType == 'Instructor Chapter')
    {
    	navPath = docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID);
        navFile = 'prefacelist.html';
    }
    else
    {
    	navPath = docRoot + computeGUIDPath(cvOID, chapOID, "null", "null");
        navFile = 'chapterlist.html';
    }

    frameContent += '<frame name="Rchapterlist_frame" scrolling="no" marginwidth="0" marginheight="0" noresize="true" target="main_frame" src="' + navPath + navFile + '">';
    frameContent += '</frame>';
    
    navPath = docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID);
    navFile = 'resourcenav.html';
    frameContent += '<frame name="Rnavigation_frame" scrolling="no" marginwidth="0" marginheight="0" noresize="true" target="_self" src="' + navPath + navFile + '">';
    frameContent += '</frame>';
    frameContent += '</frameset>';
    frameContent += '<noframes>';
    frameContent += '<body>';
    frameContent += '<p>This page uses frames, but your browser doesn\'t support them.</p>';
    frameContent += '</body>';
    frameContent += '</noframes>';
    frameContent += '</frameset>';

    main_frame.document.open();
    main_frame.document.write(frameContent);
    main_frame.document.close();
}

// This method is called directly from contentresourceframeset.
function writeContentResourceFrameset(docRoot,rioOID,rloOID,chapOID,cvOID,chapType,contextAuthor)
{

    var frameContent = "";
    var navPath = "";
    var navFile = "";

    top.currentSupport = 1;
    top.firstSupportPage = rioOID; 
    top.contentResourceID = rioOID;

    frameContent += '<frameset cols="490,301" framespacing="0" border="0" frameborder="0" onload="window.focus()">';
    frameContent += '<frameset rows="100%,57">';
    frameContent += '<frame name="media_frame" scrolling="no" marginwidth="0" marginheight="0" src="' + docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID) + 'media.html"';
    frameContent += '</frame>';


    if (chapType == 'Instructor Chapter')
    {
    	navPath = docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID);
        navFile = 'prefacelist.html';
    }
    else
    {
    	navPath = docRoot + computeGUIDPath(cvOID, chapOID, "null", "null");
        navFile = 'chapterlist.html';
    }

    frameContent += '<frame name="list_frame" scrolling="no" marginwidth="0" marginheight="0" noresize="true" target="main_frame" src="' + navPath + navFile + '">';
    frameContent += '</frame>';
    frameContent += '</frameset>';
    frameContent += '<frameset rows="100%,57">';
    frameContent += '<frame name="content_frame" scrolling="yes" marginwidth="0" marginheight="0" target="_self" src="' + docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID) + 'content.html">';
    frameContent += '</frame>';
    
    navPath = docRoot + computeGUIDPath(chapOID, chapOID, rloOID, rioOID);
    navFile = 'contentresourcenav.html';
    frameContent += '<frame name="navigation_frame" scrolling="no" marginwidth="0" marginheight="0" noresize="true" target="_self" src="' + navPath + navFile + '">';
    frameContent += '</frame>';
    frameContent += '</frameset>';
    frameContent += '<noframes>';
    frameContent += '<body>';
    frameContent += '<p>This page uses frames, but your browser doesn\'t support them.</p>';
    frameContent += '</body>';
    frameContent += '</noframes>';
    frameContent += '</frameset>';

    main_frame.document.open();
    main_frame.document.write(frameContent);
    main_frame.document.close();
}
