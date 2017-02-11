//******************************************************************************
//
// This file is part of the OpenHoldem project
//    Source code:           https://github.com/OpenHoldem/openholdembot/
//    Forums:                http://www.maxinmontreal.com/forums/index.php
//    Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//******************************************************************************
//
// Purpose: Evaluating titletext (ttlimits)
//   and the craped c0limitsX
//
//******************************************************************************

#ifndef INC_CTITLEEVALUATOR_H
#define INC_CTITLEEVALUATOR_H

class CTableEvaluator {
  friend class CDlgEditSymbols;
 public:
  CTableEvaluator();
  ~CTableEvaluator();
 public:
  void ClearAllDataOncePerHeartbeat();
  void EvaluateTitleText();
  void EvaluateScrapedTitleTexts();
 private:
  void EvaluateC0LimitsX(CString c0limitsX);
  // Process ttlimits and c0limitsX.
  // Accept only full matches, discard partial matches.
  // Aggregate data in case of multiple perfect matches.
  bool ProcessTitle(CString title, CString ttlimits_format);
 private:
  double _sblind;
  double _bblind;
  double _bbet;
  double _ante;
  double _sb_bb;
  double _bb_BB;
  double _buyin;
  int    _limit;
  CString _handnumber;
 private:
  // Verbose results for OpenScrape
  // Everything in one string
  CString _results_for_openscrape;
};

extern CTableEvaluator *p_title_evaluator;

#endif INC_CTITLEEVALUATOR_H