''' 
@file prelim.py
@brief Example that shows how to draw PHENIX preliminary logo 

How to use: call "python examples/prelim.py" from the root of the repository
For this example to work python needs to work with ROOT

This file is an example in a project PHENIXTools (https://github.com/Sergeyir/PHENIXTools).

@author Sergei Antsupov (antsupov0124@gmail.com)
'''

import os
import ROOT
# for some reason pyroot ignores rootlogon despite 
# the manual saying that it will be automatycaly loaded
# so you have to import if you use rootlogon.py
# or you can use rootlogon.C as it is done below
import rootlogon

# for some reason pyroot ignores rootlogon despite 
# the manual saying that it will be automatycaly loaded
# so you have to call this for rootlogon.C
# or import it as it is done above
# ROOT.gROOT.Macro(os.path.expanduser('rootlogon.C'))

ROOT.gInterpreter.ProcessLine('#include "LogoPainter.hpp"')

c = ROOT.TCanvas("", "", 800, 800)
ROOT.gPad.DrawFrame(0., 0., 1., 1.)

ROOT.PHENIXTools.DrawPreliminary(0.6, 0.6, 0.2)

os.system('mkdir output')
c.SaveAs('output/prelim.pdf')

input('Press ENTER to exit')
