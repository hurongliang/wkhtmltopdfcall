//
//  wkhtmltopdfcall.h
//  wkhtmltopdfcall
//
//  Created by Ron Hu on 8/5/14.
//  Copyright (c) 2014 Techpubs, Inc. All rights reserved.
//

#ifndef wkhtmltopdfcall_wkhtmltopdfcall_h
#define wkhtmltopdfcall_wkhtmltopdfcall_h

CAPI(int) htmltopdfcall(const char* html, const char* pdf);
CAPI(int) htmltopdfcallwithheader(const char* html, const char* pdf, bool header_enable, const char* header_lefttext, const char* header_centertext, const char* header_righttext, const char* header_fontname, const char* header_fontsize, bool footer_enable, const char* footer_lefttext, const char* footer_centertext, const char* footer_righttext, const char* footer_fontname, const char* footer_fontsize)

#endif
