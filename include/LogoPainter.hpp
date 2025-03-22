/** 
 *  @file  LogoPainer.hpp 
 *  @brief Contains variables and function declarations that are used to draw logos on ROOT TPad
 *
 *  This file is a part of a project PHENIXTools (https://github.com/Sergeyir/PHENIXTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef LOGO_PAINTER_HPP
#define LOGO_PAINTER_HPP

#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

#include "TText.h"
#include "TPad.h"
#include "TColor.h"
#include "TGraph.h"

/// namespace PHENIXTools
/// @brief Contains all functions and variables that are needed for this project
namespace PHENIXTools
{
   /*! @brief Draw preliminary logo on a TPad. 
    *
    * This is the only function that is needed for the user for the logo to be drawn.
    *
    * @param[in] x NDC coordinate along x axis that shows where to put the logo
    * @param[in] y NDC coordinate along y axis that shows where to put the logo
    * @param[in] size NDC size of a logo
    *
    * The logo will be drawn (in NDC) from x to x + size along X axis and from y to y + 0.4772*size along y axis.
    *
    * Warning: do not set your TPad size less than 200 pixels in width or height. 
    * This will mess up the calculation of sizes along x and y axis since pixels must be used for consistency.
    *
    * See examples how to print logo in different situtations:
    * @example prelim.cpp Shows how to use it if you compile your code with GNU GCC
    * @example cling_prelim.cpp Shows how to use it if you run your code via ROOT CLING interpreter
    * @example prelim.py Shows how to use it if you run your code via PyROOT
    */
   void DrawPreliminary(const double x, const double y, const double size = 0.25);
   /// Draws bezier shape from the points that were extracted by dividing bezier 
   /// shape in inkscape into many segments
   void DrawBezierShape(const std::string inputFileName, const double shiftX, const double shiftY,
                        const double scaleX, const double scaleY, const Color_t color);
   /// Draws rectangle
   void DrawRectangle(const double x1, const double y1, const double x2, const double y2,
                      const double x3, const double y3, const double x4, const double y4,
                      const double scaleX, const double scaleY, const Color_t color);
   /// Path to the file containing info of the red thing
   std::string redThingFile;// = RED_THING_PATH;
   /// Variable that lets TObjects have unique name so that they will not be overwritten
   int uniqueId = 0;
}

#endif /* LOGO_PAINTER_HPP */
