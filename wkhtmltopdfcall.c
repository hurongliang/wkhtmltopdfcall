//
//  wkhtmltopdfcall.c
//  wkhtmltopdfcall
//
//  Created by Ron Hu on 8/5/14.
//  Copyright (c) 2014 Techpubs, Inc. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "pdf.h"


/* Print out loading progress information */
void progress_changed(wkhtmltopdf_converter * c, int p) {
	printf("%3d%%\r",p);
	fflush(stdout);
}

/* Print loading phase information */
void phase_changed(wkhtmltopdf_converter * c) {
	int phase = wkhtmltopdf_current_phase(c);
	printf("%s\n", wkhtmltopdf_phase_description(c, phase));
}

/* Print a message to stderr when an error occures */
void error(wkhtmltopdf_converter * c, const char * msg) {
	fprintf(stderr, "Error: %s\n", msg);
}

/* Print a message to stderr when a warning is issued */
void warning(wkhtmltopdf_converter * c, const char * msg) {
	fprintf(stderr, "Warning: %s\n", msg);
}

int htmltopdfcallwithsettings(const char* page, const char* out,
                              const char* sizePaperSize,
                              const char* sizeWidth,
                              const char* sizeHeight,
                              const char* orientation,
                              const char* colorMode,
                              const char* resolution,
                              const char* dpi,
                              const char* pageOffset,
                              const char* copies,
                              const char* collate,
                              const char* outline,
                              const char* outlineDepth,
                              const char* dumpOutline,
                              const char* documentTitle,
                              const char* useCompression,
                              const char* marginTop,
                              const char* marginBottom,
                              const char* marginLeft,
                              const char* marginRight,
                              const char* imageDPI,
                              const char* imageQuality,
                              const char* loadCookieJar,
                              
                              const char* tocUseDottedLines,
                              const char* tocCaptionText,
                              const char* tocForwardLinks,
                              const char* tocBackLinks,
                              const char* tocIndentation,
                              const char* tocFontScale,
                              const char* useExternalLinks,
                              const char* useLocalLinks,
                              const char* replacements,
                              const char* produceForms,
                              const char* includeInOutline,
                              const char* pagesCount,
                              const char* tocXsl,
                              
                              const char* webBackground,
                              const char* webLoadImages,
                              const char* webEnableJavascript,
                              const char* webEnableIntelligentShrinking,
                              const char* webMinimumFontSize,
                              const char* webPrintMediaType,
                              const char* webDefaultEncoding,
                              const char* webUserStyleSheet,
                              const char* webEnablePlugins,
                              
                              const char* headerFontSize,
                              const char* headerFontName,
                              const char* headerLeft,
                              const char* headerCenter,
                              const char* headerRight,
                              const char* headerLine,
                              const char* headerSpacing,
                              const char* headerHtmlUrl,
                              
                              const char* footerFontSize,
                              const char* footerFontName,
                              const char* footerLeft,
                              const char* footerCenter,
                              const char* footerRight,
                              const char* footerLine,
                              const char* footerSpacing,
                              const char* footerHtmlUrl,
                              
                              const char* loadUsername,
                              const char* loadPassword,
                              const char* loadJsdelay,
                              const char* loadZoomFactor,
                              const char* loadCustomHeaders,
                              const char* loadRepertCustomHeaders,
                              const char* loadCookies,
                              const char* loadPost,
                              const char* loadBlockLocalFileAccess,
                              const char* loadStopSlowScript,
                              const char* loadDebugJavascript,
                              const char* loadLoadErrorHandling,
                              const char* loadProxy,
                              const char* loadRunScript){
    wkhtmltopdf_global_settings * gs;
    wkhtmltopdf_object_settings * os;
    wkhtmltopdf_converter * c;
    
    /* Init wkhtmltopdf in graphics less mode */
    wkhtmltopdf_init(false);
    
    /*
     * Create a global settings object used to store options that are not
     * related to input objects, note that control of this object is parsed to
     * the converter later, which is then responsible for freeing it
     */
    gs = wkhtmltopdf_create_global_settings();
    /* We want the result to be storred in the file called test.pdf */
    wkhtmltopdf_set_global_setting(gs, "out", out);
    
    if(sizePaperSize!=NULL){wkhtmltopdf_set_global_setting(gs, "size.paperSize",sizePaperSize);}
    if(sizeWidth!=NULL){wkhtmltopdf_set_global_setting(gs, "size.width",sizeWidth);}
    if(sizeHeight!=NULL){wkhtmltopdf_set_global_setting(gs, "size.height",sizeHeight);}
    if(orientation!=NULL){wkhtmltopdf_set_global_setting(gs, "orientation",orientation);}
    if(colorMode!=NULL){wkhtmltopdf_set_global_setting(gs, "colorMode",colorMode);}
    if(resolution!=NULL){wkhtmltopdf_set_global_setting(gs, "resolution",resolution);}
    if(dpi!=NULL){wkhtmltopdf_set_global_setting(gs, "dpi",dpi);}
    if(pageOffset!=NULL){wkhtmltopdf_set_global_setting(gs, "pageOffset",pageOffset);}
    if(copies!=NULL){wkhtmltopdf_set_global_setting(gs, "copies",copies);}
    if(collate!=NULL){wkhtmltopdf_set_global_setting(gs, "collate",collate);}
    if(outline!=NULL){wkhtmltopdf_set_global_setting(gs, "outline",outline);}
    if(outlineDepth!=NULL){wkhtmltopdf_set_global_setting(gs, "outlineDepth",outlineDepth);}
    if(dumpOutline!=NULL){wkhtmltopdf_set_global_setting(gs, "dumpOutline",dumpOutline);}
    if(documentTitle!=NULL){wkhtmltopdf_set_global_setting(gs, "documentTitle",documentTitle);}
    if(useCompression!=NULL){wkhtmltopdf_set_global_setting(gs, "useCompression",useCompression);}
    if(marginTop!=NULL){wkhtmltopdf_set_global_setting(gs, "margin.top",marginTop);}
    if(marginBottom!=NULL){wkhtmltopdf_set_global_setting(gs, "margin.bottom",marginBottom);}
    if(marginLeft!=NULL){wkhtmltopdf_set_global_setting(gs, "margin.left",marginLeft);}
    if(marginRight!=NULL){wkhtmltopdf_set_global_setting(gs, "margin.right",marginRight);}
    if(imageDPI!=NULL){wkhtmltopdf_set_global_setting(gs, "imageDPI",imageDPI);}
    if(imageQuality!=NULL){wkhtmltopdf_set_global_setting(gs, "imageQuality",imageQuality);}
    if(loadCookieJar!=NULL){wkhtmltopdf_set_global_setting(gs, "load.cookieJar",loadCookieJar);}
    
    //wkhtmltopdf_set_global_setting(gs, "load.cookieJar", "myjar.jar");
    /*
     * Create a input object settings object that is used to store settings
     * related to a input object, note again that control of this object is parsed to
     * the converter later, which is then responsible for freeing it
     */
    os = wkhtmltopdf_create_object_settings();
    /* We want to convert to convert the qstring documentation page */
    wkhtmltopdf_set_object_setting(os, "page", page);
    
    /*
     * Set page header information
     */
    
    if(tocUseDottedLines!=NULL){wkhtmltopdf_set_object_setting(os, "toc.useDottedLines",tocUseDottedLines);}
    if(tocCaptionText!=NULL){wkhtmltopdf_set_object_setting(os, "toc.captionText",tocCaptionText);}
    if(tocForwardLinks!=NULL){wkhtmltopdf_set_object_setting(os, "toc.forwardLinks",tocForwardLinks);}
    if(tocBackLinks!=NULL){wkhtmltopdf_set_object_setting(os, "toc.backLinks",tocBackLinks);}
    if(tocIndentation!=NULL){wkhtmltopdf_set_object_setting(os, "toc.indentation",tocIndentation);}
    if(tocFontScale!=NULL){wkhtmltopdf_set_object_setting(os, "toc.fontScale",tocFontScale);}
    if(useExternalLinks!=NULL){wkhtmltopdf_set_object_setting(os, "useExternalLinks",useExternalLinks);}
    if(useLocalLinks!=NULL){wkhtmltopdf_set_object_setting(os, "useLocalLinks",useLocalLinks);}
    if(replacements!=NULL){wkhtmltopdf_set_object_setting(os, "replacements",replacements);}
    if(produceForms!=NULL){wkhtmltopdf_set_object_setting(os, "produceForms",produceForms);}
    if(includeInOutline!=NULL){wkhtmltopdf_set_object_setting(os, "includeInOutline",includeInOutline);}
    if(pagesCount!=NULL){wkhtmltopdf_set_object_setting(os, "pagesCount",pagesCount);}
    if(tocXsl!=NULL){wkhtmltopdf_set_object_setting(os, "tocXsl",tocXsl);}
    
    if(webBackground!=NULL){wkhtmltopdf_set_object_setting(os, "web.background ",webBackground);}
    if(webLoadImages!=NULL){wkhtmltopdf_set_object_setting(os, "web.loadImages",webLoadImages);}
    if(webEnableJavascript!=NULL){wkhtmltopdf_set_object_setting(os, "web.enableJavascript",webEnableJavascript);}
    if(webEnableIntelligentShrinking!=NULL){wkhtmltopdf_set_object_setting(os, "web.enableIntelligentShrinking",webEnableIntelligentShrinking);}
    if(webMinimumFontSize!=NULL){wkhtmltopdf_set_object_setting(os, "web.minimumFontSize",webMinimumFontSize);}
    if(webPrintMediaType!=NULL){wkhtmltopdf_set_object_setting(os, "web.printMediaType",webPrintMediaType);}
    if(webDefaultEncoding!=NULL){wkhtmltopdf_set_object_setting(os, "web.defaultEncoding",webDefaultEncoding);}
    if(webUserStyleSheet!=NULL){wkhtmltopdf_set_object_setting(os, "web.userStyleSheet",webUserStyleSheet);}
    if(webEnablePlugins!=NULL){wkhtmltopdf_set_object_setting(os, "web.enablePlugins",webEnablePlugins);}
    
    if(headerFontSize!=NULL){wkhtmltopdf_set_object_setting(os, "header.fontSize",headerFontSize);}
    if(headerFontName!=NULL){wkhtmltopdf_set_object_setting(os, "header.fontName",headerFontName);}
    if(headerLeft!=NULL){wkhtmltopdf_set_object_setting(os, "header.left",headerLeft);}
    if(headerCenter!=NULL){wkhtmltopdf_set_object_setting(os, "header.center",headerCenter);}
    if(headerRight!=NULL){wkhtmltopdf_set_object_setting(os, "header.right",headerRight);}
    if(headerLine!=NULL){wkhtmltopdf_set_object_setting(os, "header.line",headerLine);}
    if(headerSpacing!=NULL){wkhtmltopdf_set_object_setting(os, "header.spacing",headerSpacing);}
    if(headerHtmlUrl!=NULL){wkhtmltopdf_set_object_setting(os, "header.htmlUrl",headerHtmlUrl);}
    
    if(footerFontSize!=NULL){wkhtmltopdf_set_object_setting(os, "footer.fontSize",footerFontSize);}
    if(footerFontName!=NULL){wkhtmltopdf_set_object_setting(os, "footer.fontName",footerFontName);}
    if(footerLeft!=NULL){wkhtmltopdf_set_object_setting(os, "footer.left",footerLeft);}
    if(footerCenter!=NULL){wkhtmltopdf_set_object_setting(os, "footer.center",footerCenter);}
    if(footerRight!=NULL){wkhtmltopdf_set_object_setting(os, "footer.right",footerRight);}
    if(footerLine!=NULL){wkhtmltopdf_set_object_setting(os, "footer.line",footerLine);}
    if(footerSpacing!=NULL){wkhtmltopdf_set_object_setting(os, "footer.spacing",footerSpacing);}
    if(footerHtmlUrl!=NULL){wkhtmltopdf_set_object_setting(os, "footer.htmlUrl",footerHtmlUrl);}
    
    if(loadUsername!=NULL){wkhtmltopdf_set_object_setting(os, "load.username",loadUsername);}
    if(loadPassword!=NULL){wkhtmltopdf_set_object_setting(os, "load.password",loadPassword);}
    if(loadJsdelay!=NULL){wkhtmltopdf_set_object_setting(os, "load.jsdelay ",loadJsdelay);}
    if(loadZoomFactor!=NULL){wkhtmltopdf_set_object_setting(os, "load.zoomFactor",loadZoomFactor);}
    if(loadCustomHeaders!=NULL){wkhtmltopdf_set_object_setting(os, "load.customHeaders",loadCustomHeaders);}
    if(loadRepertCustomHeaders!=NULL){wkhtmltopdf_set_object_setting(os, "load.repertCustomHeaders",loadRepertCustomHeaders);}
    if(loadCookies!=NULL){wkhtmltopdf_set_object_setting(os, "load.cookies",loadCookies);}
    if(loadPost!=NULL){wkhtmltopdf_set_object_setting(os, "load.post",loadPost);}
    if(loadBlockLocalFileAccess!=NULL){wkhtmltopdf_set_object_setting(os, "load.blockLocalFileAccess",loadBlockLocalFileAccess);}
    if(loadStopSlowScript!=NULL){wkhtmltopdf_set_object_setting(os, "load.stopSlowScript",loadStopSlowScript);}
    if(loadDebugJavascript!=NULL){wkhtmltopdf_set_object_setting(os, "load.debugJavascript",loadDebugJavascript);}
    if(loadLoadErrorHandling!=NULL){wkhtmltopdf_set_object_setting(os, "load.loadErrorHandling",loadLoadErrorHandling);}
    if(loadProxy!=NULL){wkhtmltopdf_set_object_setting(os, "load.proxy",loadProxy);}
    if(loadRunScript!=NULL){wkhtmltopdf_set_object_setting(os, "load.runScript",loadRunScript);}
    
    /* Create the actual converter object used to convert the pages */
    c = wkhtmltopdf_create_converter(gs);
    
    /* Call the progress_changed function when progress changes */
    wkhtmltopdf_set_progress_changed_callback(c, progress_changed);
    
    /* Call the phase _changed function when the phase changes */
    wkhtmltopdf_set_phase_changed_callback(c, phase_changed);
    
    /* Call the error function when an error occures */
    wkhtmltopdf_set_error_callback(c, error);
    
    /* Call the warning function when a warning is issued */
    wkhtmltopdf_set_warning_callback(c, warning);
    
    /*
     * Add the the settings object describing the qstring documentation page
     * to the list of pages to convert. Objects are converted in the order in which
     * they are added
     */
    wkhtmltopdf_add_object(c, os, NULL);
    
    /* Perform the actual convertion */
    if (!wkhtmltopdf_convert(c))
        fprintf(stderr, "Convertion failed!");
    
    /* Output possible http error code encountered */
    printf("httpErrorCode: %d\n", wkhtmltopdf_http_error_code(c));
    
    /* Destroy the converter object since we are done with it */
    wkhtmltopdf_destroy_converter(c);
    
    /* We will no longer be needing wkhtmltopdf funcionality */
    wkhtmltopdf_deinit();
    
    return 0;
}