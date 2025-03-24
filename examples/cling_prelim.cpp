/** 
 *  @file cling_prelim.cpp 
 *  @brief Example that shows how to draw PHENIX preliminary logo 
 *
 *  How to use: call "root examples/cling_prelim.cpp" from the root of the repository
 *  Also see rootlogon.C on how to load libraries and include directories
 *
 *  This file is an example in a project PHENIXTools (https://github.com/Sergeyir/PHENIXTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#include "LogoPainter.hpp"

void cling_prelim()
{
   // This canvas is an example; you can use your own
   TCanvas *c = new TCanvas("", "", 800, 800);
   gPad->DrawFrame(0., 0., 1., 1.);

   // Only this function is needed to draw the logo
   PHENIXTools::DrawPreliminary(0.6, 0.6, 0.2);

   system("mkdir output");
   c->SaveAs("output/prelim.pdf");
}
