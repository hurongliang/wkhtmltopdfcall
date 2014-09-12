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
int htmltopdfcallwithheader(const char* html, const char* pdf, bool header_enable, const char* header_lefttext, const char* header_centertext, const char* header_righttext, const char* header_fontname, const char* header_fontsize, bool header_line, const char* header_spacing, bool footer_enable, const char* footer_lefttext, const char* footer_centertext, const char* footer_righttext, const char* footer_fontname, const char* footer_fontsize, bool footer_line, const char* footer_spacing, const char* margin_left, const char* margin_right, const char* margin_top, const char* margin_bottom, bool print_media_type){
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
	wkhtmltopdf_set_global_setting(gs, "out", pdf);
    
    if(margin_left!=NULL){
        wkhtmltopdf_set_global_setting(gs, "margin.left", margin_left);
    }
    if(margin_right!=NULL){
        wkhtmltopdf_set_global_setting(gs, "margin.right", margin_right);
    }
    if(margin_top!=NULL){
        wkhtmltopdf_set_global_setting(gs, "margin.top", margin_top);
    }
    if(margin_bottom!=NULL){
        wkhtmltopdf_set_global_setting(gs, "margin.bottom", margin_bottom);
    }
    
	//wkhtmltopdf_set_global_setting(gs, "load.cookieJar", "myjar.jar");
	/*
	 * Create a input object settings object that is used to store settings
	 * related to a input object, note again that control of this object is parsed to
	 * the converter later, which is then responsible for freeing it
	 */
	os = wkhtmltopdf_create_object_settings();
	/* We want to convert to convert the qstring documentation page */
	wkhtmltopdf_set_object_setting(os, "page", html);
    
    /*
     * Set page header information
     */
    if(header_enable==true){
        if(header_lefttext!=NULL){
            wkhtmltopdf_set_object_setting(os, "header.left", header_lefttext);
        }
        if(header_centertext!=NULL){
            wkhtmltopdf_set_object_setting(os, "header.center", header_centertext);
        }
        if(header_righttext!=NULL){
            wkhtmltopdf_set_object_setting(os, "header.right", header_righttext);
        }
        if(header_fontname!=NULL){
            wkhtmltopdf_set_object_setting(os, "header.fontName", header_fontname);
        }
        if(header_fontsize!=NULL){
            wkhtmltopdf_set_object_setting(os, "header.fontSize", header_fontsize);
        }
        if(header_line==true){
            wkhtmltopdf_set_object_setting(os, "header.line", "true");
        }else{
            wkhtmltopdf_set_object_setting(os, "header.line", "false");
        }
        if(header_spacing!=NULL){
            wkhtmltopdf_set_object_setting(os,"header.spacing",header_spacing);
        }
    }
    /*
     * Set page footer information
     */
    if(footer_enable==true){
        if(footer_lefttext!=NULL){
            wkhtmltopdf_set_object_setting(os, "footer.left", footer_lefttext);
        }
        if(footer_centertext!=NULL){
            wkhtmltopdf_set_object_setting(os, "footer.center", footer_centertext);
        }
        if(footer_righttext!=NULL){
            wkhtmltopdf_set_object_setting(os, "footer.right", footer_righttext);
        }
        if(footer_fontname!=NULL){
            wkhtmltopdf_set_object_setting(os, "footer.fontName", footer_fontname);
        }
        if(footer_fontsize!=NULL){
            wkhtmltopdf_set_object_setting(os, "footer.fontSize", footer_fontsize);
        }
        if(footer_line==true){
            wkhtmltopdf_set_object_setting(os, "footer.line", "true");
        }else{
            wkhtmltopdf_set_object_setting(os, "footer.line", "false");
        }
        if(footer_spacing!=NULL){
            wkhtmltopdf_set_object_setting(os,"footer.spacing",footer_spacing);
        }
    }
    
    if(print_media_type==true){
        wkhtmltopdf_set_object_setting(os,"web.printMediaType","true");
    }else{
        wkhtmltopdf_set_object_setting(os,"web.printMediaType","false");
    }
    
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

int htmltopdfcall(const char* html, const char* pdf){
    return htmltopdfcallwithheader(html, pdf, false, NULL, NULL, NULL, NULL, NULL,false,NULL,false,NULL,NULL,NULL,NULL,NULL,false,NULL,NULL,NULL,NULL,NULL,false);
}