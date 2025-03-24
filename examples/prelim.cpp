/** 
 *  @file prelim.cpp 
 *  @brief Example that shows how to draw PHENIX preliminary logo 
 *
 *  How to use: call the executable that is located in bin directory located in root of the repository after the compilation
 *
 *  This file is an example in a project PHENIXTools (https://github.com/Sergeyir/PHENIXTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#include "TCanvas.h"

#include "LogoPainter.hpp"

int main()
{
   // This canvas is an example; you can use your own
   TCanvas c("", "", 800, 800);
   gPad->DrawFrame(0., 0., 1., 1.);

   // Only this function is needed to draw the logo
   PHENIXTools::DrawPreliminary(0.6, 0.6, 0.2);

   system("mkdir output");
   c.SaveAs("output/prelim.pdf");

   return 0;
}
