﻿//----------------------------------------------------------------------------
//  Copyright (C) 2004-2013 by EMGU. All rights reserved.       
//----------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;
using Emgu.CV;
using Emgu.CV.Structure;
using Emgu.CV.Util;
using Emgu.Util;

namespace Emgu.CV.Features2D
{
   /// <summary>
   /// The FREAK (Fast Retina Keypoint) keypoint descriptor:
   /// Alahi, R. Ortiz, and P. Vandergheynst. FREAK: Fast Retina Keypoint. In IEEE Conference on Computer
   /// Vision and Pattern Recognition, 2012. CVPR 2012 Open Source Award Winner.
   /// The algorithm
   /// propose a novel keypoint descriptor inspired by the human visual system and more precisely the retina, coined Fast
   /// Retina Key- point (FREAK). A cascade of binary strings is computed by efficiently comparing image intensities over a
   /// retinal sampling pattern. FREAKs are in general faster to compute with lower memory load and also more robust than
   /// SIFT, SURF or BRISK. They are competitive alternatives to existing keypoints in particular for embedded applications.
   /// </summary>
   public class Freak : UnmanagedObject, IDescriptorExtractor
   {
      static Freak()
      {
         CvInvoke.CheckLibraryLoaded();
      }

      private IntPtr _descriptorExtractorPtr;

      /// <summary>
      /// Create a Freak descriptor extractor.
      /// </summary>
      /// <param name="orientationNormalized">Enable orientation normalization</param>
      /// <param name="scaleNormalized">Enable scale normalization</param>
      /// <param name="patternScale">Scaling of the description pattern</param>
      /// <param name="nOctaves">Number of octaves covered by the detected keypoints.</param>
      public Freak(bool orientationNormalized = true, bool scaleNormalized = true, float patternScale = 22.0f, int nOctaves = 4)
      {
         _ptr = CvFreakCreate(orientationNormalized, scaleNormalized, patternScale, nOctaves, ref _descriptorExtractorPtr);
      }

      /// <summary>
      /// Release all the unmanaged resource associated with BRIEF
      /// </summary>
      protected override void DisposeObject()
      {
         if (_ptr != IntPtr.Zero)
            CvFreakRelease(ref _ptr);
      }

      IntPtr IDescriptorExtractor.DescriptorExtratorPtr
      {
         get { return _descriptorExtractorPtr; }
      }

      [DllImport(CvInvoke.EXTERN_LIBRARY, CallingConvention = CvInvoke.CvCallingConvention)]
      internal extern static IntPtr CvFreakCreate(
         [MarshalAs(CvInvoke.BoolMarshalType)]
         bool orientationNormalized,
         [MarshalAs(CvInvoke.BoolMarshalType)]
         bool scaleNormalized,
         float patternScale,
         int nOctaves, 
         ref IntPtr descriptorExtractorPtr);

      [DllImport(CvInvoke.EXTERN_LIBRARY, CallingConvention = CvInvoke.CvCallingConvention)]
      internal extern static void CvFreakRelease(ref IntPtr extractor);
   }
}

