/*
 * Copyright 2010 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Author: jmarantz@google.com (Joshua Marantz)

#ifndef NET_INSTAWEB_HTMLPARSE_PUBLIC_HTML_NAME_H_
#define NET_INSTAWEB_HTMLPARSE_PUBLIC_HTML_NAME_H_

#include "net/instaweb/util/public/string_util.h"

namespace net_instaweb {

// HTML names are case insensitive.  However, in the parser, we keep
// the original parsed case of the name, in addition to the html
// keyword enumeration, if any.  Thus for both tags and attribute
// names, we have an enum representation which is used in filters
// for scanning, plus we have the original string representation.
class HtmlName {
 public:
  // We keep both attribute names and tag names in the same space
  // for convenience.  This list must be kept in alpha-order and
  // in sync with the static array in html_name.cc.
  //
  // Note that this list does not need to cover all HTML keywords --
  // only the ones that we are interested in for rewriting.
  enum Keyword {
    kXml,  // ?Xml
    kA,
    kAlt,
    kArea,
    kAsync,
    kAudio,
    kAutocomplete,
    kAutofocus,
    kAutoplay,
    kBase,
    kBody,
    kBr,
    kButton,
    kCharset,
    kChecked,
    kClass,
    kCol,
    kColgroup,
    kColspan,
    kCommand,
    kContent,
    kControls,
    kDd,
    kDeclare,
    kDefaultchecked,
    kDefaultselected,
    kDefer,
    kDetails,
    kDisabled,
    kDisplay,
    kDiv,
    kDt,
    kEnctype,
    kEvent,
    kFor,
    kForm,
    kFormnovalidate,
    kFrame,
    kFrameborder,
    kHead,
    kHeight,
    kHr,
    kHref,
    kHtml,
    kHttpEquiv,
    kId,
    kIframe,
    kImg,
    kIndeterminate,
    kInput,
    kIsmap,
    kKeygen,
    kKeytype,
    kLang,
    kLanguage,
    kLi,
    kLink,
    kLoop,
    kMedia,
    kMenu,
    kMeta,
    kMethod,
    kMultiple,
    kMuted,
    kName,
    kNohref,
    kNoresize,
    kNoscript,
    kNovalidate,
    kObject,
    kOl,
    kOnclick,
    kOpen,
    kOptgroup,
    kOption,
    kOther,
    kP,
    kPagespeedHighResSrc,
    kPagespeedLowResSrc,
    kParam,
    kPre,
    kReadonly,
    kRel,
    kRequired,
    kReversed,
    kRowspan,
    kRp,
    kRt,
    kScoped,
    kScript,
    kScrolling,
    kSeamless,
    kSelect,
    kSelected,
    kShape,
    kSource,
    kSpan,
    kSrc,
    kStyle,
    kTag,
    kTbody,
    kTd,
    kTest,
    kTextarea,
    kTfoot,
    kTh,
    kThead,
    kTr,
    kType,
    kValuetype,
    kVideo,
    kXmp,
    kWbr,
    kWidth,
    kWrap,
    kNotAKeyword
  };

  // Constructs an HTML name given a keyword, which can be
  // HtmlName::kNotAKeyword, and 'const char* str'.  'str'
  // is used to retain the case-sensitive spelling of the
  // keyword.  The storage for 'str' must be managed, and
  // must be guaranteed valid throughout the life of the HtmlName.
  HtmlName(Keyword keyword, const char* str)
      : keyword_(keyword), c_str_(str) {
  }

  // Returns the keyword enumeration for this HTML Name.  Note that
  // keyword lookup is case-insensitive.
  Keyword keyword() const { return keyword_; }

  // Return the atom string, which may not be case folded.
  const char* c_str() const { return c_str_; }

  // Limited iterator (not an STL iterator).  Example usage:
  //    for (HtmlName::Iterator iter; !iter.AtEnd(); iter.Next()) {
  //      use(iter.keyword(), iter.name());
  //    }
  class Iterator {
   public:
    Iterator() : index_(-1) { Next(); }
    bool AtEnd() const;
    void Next();
    Keyword keyword() const;
    const char* name() const;

   private:
    int index_;

    // Implicit copy and assign ok.  The members can be safely copied by bits.
  };

  static int num_keywords();
  static Keyword Lookup(const StringPiece& name);

 private:
  friend class HtmlNameTest;

  Keyword keyword_;
  const char* c_str_;

  // Implicit copy and assign ok.  The members can be safely copied by bits.
};

}  // namespace net_instaweb

#endif  // NET_INSTAWEB_HTMLPARSE_PUBLIC_HTML_NAME_H_
