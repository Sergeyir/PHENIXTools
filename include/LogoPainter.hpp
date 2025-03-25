/** 
 *  @file  LogoPainer.hpp 
 *  @brief Contains variables and function declarations that are used to draw logos on ROOT TPad
 *
 *  This file is a part of a project PHENIXTools (https://github.com/Sergeyir/PHENIXTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef PHENIX_TOOLS_LOGO_PAINTER_HPP
#define PHENIX_TOOLS_LOGO_PAINTER_HPP

#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

#include "TText.h"
#include "TPad.h"
#include "TColor.h"
#include "TGraph.h"

/*! @namespace PHENIXTools
 *  @brief Contains all functions and variables that are needed for this project
 *
 *  @example prelim.cpp
 */
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
    * Warning: do not set your TPad size less than 400 pixels in width or height. 
    * This might mess up the calculation of sizes of the logo along x and y axis since pixels must be used for consistency.
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
   /// Variable that lets TObjects have unique name so that they will not be overwritten
   int uniqueId = 0;
}

#endif /* PHENIX_TOOLS_LOGO_PAINTER_HPP */
