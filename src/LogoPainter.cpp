/** 
 *  @file  LogoPainer.cpp 
 *  @brief Contains functions realisations that are used to draw logos on ROOT TPad
 *
 *  This file is a part of a project PHENIXTools (https://github.com/Sergeyir/PHENIXTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef LOGO_PAINTER_CPP
#define LOGO_PAINTER_CPP

#include "../include/LogoPainter.hpp"

void PHENIXTools::DrawPreliminary(const double x, const double y, const double size)
{
   if (!gPad)
   {
      std::cout << "Error: No TPad was created before drawing logo" << std::endl;
      exit(1);
   }

   gPad->Update();

   const double scaleX = 1./190.417;
   const double scaleY = 1./91.363;

   const double xMax = x + (gPad->PixeltoX((gPad->UtoPixel(size))) - gPad->PixeltoX(0))/
                           (gPad->GetX2() - gPad->GetX1());
   const double yMax = y + (gPad->PixeltoY(0) - gPad->PixeltoY((gPad->UtoPixel(size*0.47729))))/
                           (gPad->GetY2() - gPad->GetY1());

   TPad *logoPad = new TPad(("PHENIX_logo_" + std::to_string(uniqueId)).c_str(), "", 0., 0., 1., 1.);

   //logoPad->SetFillColor(kGray); // for testing
   logoPad->SetFillStyle(4000);

   uniqueId++;

   logoPad->SetPad(x, y, xMax, yMax);

   logoPad->Draw();
   logoPad->cd();
   logoPad->Update();

   TText normalText;
   TText boldText; 

   normalText.SetTextFont(42);
   boldText.SetTextFont(62);

   normalText.SetTextSize(0.5/1.076);
   boldText.SetTextSize(0.5/1.03);

   normalText.DrawText(-0.0115, 0.094, "preliminary");
   boldText.DrawText(0., 0.43, "PH");
   boldText.DrawText(0.485, 0.43, "ENIX");

   for (double phi = M_PI/12.; phi < M_PI*2.; phi += M_PI/6.)
   {
      DrawRectangle(75.13 + cos(phi)*3.35 + sin(phi)*0.66, 
                    91.363 - 37.44 + sin(phi)*3.55 - cos(phi)*0.66, 
                    75.13 + cos(phi)*3.35 - sin(phi)*0.66, 
                    91.363 - 37.44 + sin(phi)*3.55 + cos(phi)*0.66,
                    75.13 + cos(phi)*18.01 - sin(phi)*0.66, 
                    91.363 - 37.44 + sin(phi)*18.01 + cos(phi)*0.66,
                    75.13 + cos(phi)*18.01 + sin(phi)*0.66, 
                    91.363 - 37.44 + sin(phi)*18.01 - cos(phi)*0.66,
                    scaleX, scaleY, 14);
   }

   DrawBezierShape(RED_THING_PATH, 75.13, 91.363 - 19.43, scaleX, scaleY, 2);
}

void PHENIXTools::DrawBezierShape(const std::string inputFileName, 
                                 const double shiftX, const double shiftY,
                                 const double scaleX, const double scaleY, 
                                 const Color_t color)
{
   TGraph graph;
   std::ifstream inputFile(inputFileName);

   double anchor1x, anchor1y, anchor2x, anchor2y, x, y;
   while (inputFile >> anchor1x >> anchor1y >> anchor2x >> anchor2y >> x >> y)
   {
      x += anchor2x - anchor1x;
      y += anchor2y - anchor1y;
      if (graph.GetN() != 0)
      {
         graph.AddPoint(x + graph.GetPointX(graph.GetN() - 1), 
                        y + graph.GetPointY(graph.GetN()-1));
      }
      else
      {
         graph.AddPoint(x, y);
      }
   }

   for (int i = 0; i < graph.GetN(); i++)
   {
      graph.SetPointX(i, (graph.GetPointX(i) + shiftX)*scaleX);
      graph.SetPointY(i, (graph.GetPointY(i) + shiftY)*scaleY);
   }

   graph.SetFillStyle(1001);
   graph.SetFillColor(color);
   graph.DrawClone("F");
}

void PHENIXTools::DrawRectangle(const double x1, const double y1, const double x2, const double y2,
                               const double x3, const double y3, const double x4, const double y4,
                               const double scaleX, const double scaleY, const Color_t color)
{
   TGraph graph;

   graph.AddPoint(x1*scaleX, y1*scaleY);
   graph.AddPoint(x2*scaleX, y2*scaleY);
   graph.AddPoint(x3*scaleX, y3*scaleY);
   graph.AddPoint(x4*scaleX, y4*scaleY);

   graph.SetFillStyle(1001);
   graph.SetFillColor(color);
   graph.DrawClone("F");
}

#endif /* LOGO_PAINTER_CPP */
