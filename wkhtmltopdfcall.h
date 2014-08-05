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
CAPI(int) htmltopdfcallwithheader(const char* html, const char* pdf, bool headerenable, const char* lefttext, const char*centertext, const char* righttext, const char* fontname, const char* fontsize)

#endif
