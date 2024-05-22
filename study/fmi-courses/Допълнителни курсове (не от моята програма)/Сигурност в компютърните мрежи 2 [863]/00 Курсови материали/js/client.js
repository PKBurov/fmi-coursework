//****************************************************************************
//  File:           client.js
//
//  Description:    UNICON JavaScript Library client system detection module.
//                  It provides a means to identify the clients browser and
//                  the available plug-ins.
//
//  Author:         Shawn Lonas
//
//  Copyright:      @2001 UNICON, Inc.
//****************************************************************************
/**
*   Owner:          Shawn Lonas
*
*   Version:        $Revision: 1.1 $
*/

///////////////////////////////////// ClientSnifferJr Object Constructor

function ClientSnifferSuper()
{
    this.ua = navigator.userAgent.toLowerCase();
    this.major = parseInt(navigator.appVersion);
    this.minor = parseFloat(navigator.appVersion);
    // Operating System
    this.OS = navigator.platform;
    // DOM Support
    if (document.addEventListener && document.removeEventListener) this.dom2events = true;
    if (document.getElementById) this.dom1getbyid = true;
    // Opera
    this.opera = this.ua.indexOf('opera') != -1;
    if (this.opera) {
        if (this.ua.indexOf("opera 5") != -1 || this.ua.indexOf("opera/5") != -1) {
            this.browserVersion = 5;
        }
        this.browserType = "opera"
        return;
    }  
    // MSIE
    this.ie = this.ua.indexOf('msie') != -1;
    if (this.ie) {
          if (this.major < 4) {
            this.browserVersion = 3;
        }
        if (this.major == 4 && this.ua.indexOf('msie 5') == -1 && this.ua.indexOf('msie 6') == -1) {
            this.browserVersion = major;
        }
        if (this.major == 4 && this.ua.indexOf('msie 5.0') != -1) {
            this.browserVersion = 5;
        }
        if (this.major == 4 && this.ua.indexOf('msie 5.5') != -1) {
            this.browserVersion = 5.5;
        }
        if (this.major == 4 && this.ua.indexOf('msie 6.0') != -1) {
            this.browserVersion = 6;
        }
        this.browserType = "IE"
        return;
    }
    // Misc.
    if (this.ua.indexOf('hotjava') != -1) {
        this.browserType = "hotjava";
    } 
    if (this.ua.indexOf('webtv') != -1) {
        this.browserType = "webtv";
    }
    if (this.ua.indexOf('aol') != -1) {
        this.browserType = "aol";
    }
    if (this.hotjava || this.webtv || this.aol) return;
    // Gecko, NN4+, and NS6
    this.nav = (this.ua.indexOf('mozilla') != -1 && this.ua.indexOf('spoofer') == -1 && this.ua.indexOf('compatible') == -1);
    if (this.nav) {
        if (this.major == 4) {
            this.browserVersion = this.minor;
        }
        if (this.major == 5) {
            this.browserVersion = this.minor;
        }
        if (this.major == 5 && this.ua.indexOf('netscape6') != -1) {
            this.browserVersion = 6;
        }
        this.browserType = "NS"
        return;
    }
}
// Subclass reference is the same as the superclass unless browser specific
var ClientSniffer = ClientSnifferSuper; 

window.navigator.inheritFrom = ClientSniffer;
window.navigator.inheritFrom();

// End cbe_core.js


/*  
*   <!-- UNICOMMENT 
*
*       Change History:
*
*   $Log: client.js,v $
*   Revision 1.1  2002/07/31 03:24:22  ahaws
*   new support for MI and the workflow around it
*
*   Revision 1.4  2002/01/02 18:07:28  mpollack
*   no message
*
*   Revision 1.3  2001/12/05 21:16:58  mpollack
*   changed clientSystemInfo to be inhited into the window.navigator browser object
*
*   Revision 1.2  2001/11/12 17:09:27  shawn
*   Inherited ClientSnifferJr object directly into Navigator object (removed is property)
*
*   Revision 1.1  2001/11/08 17:48:58  shawn
*   add base js library functions
*
*
*   UNICOMMENT -->
*/
