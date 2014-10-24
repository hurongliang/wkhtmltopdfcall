//
//  wkhtmltopdfcall.h
//  wkhtmltopdfcall
//
//  Created by Ron Hu on 8/5/14.
//  Copyright (c) 2014 Techpubs, Inc. All rights reserved.
//

#ifndef wkhtmltopdfcall_wkhtmltopdfcall_h
#define wkhtmltopdfcall_wkhtmltopdfcall_h

CAPI(int) htmltopdfcallwithsettings(const char* page, const char* out,
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
                                  const char* loadRunScript);

#endif
