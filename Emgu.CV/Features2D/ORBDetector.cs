﻿//----------------------------------------------------------------------------
//  Copyright (C) 2004-2013 by EMGU. All rights reserved.       
//----------------------------------------------------------------------------

﻿using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;
using Emgu.CV.Structure;
using Emgu.CV.Util;
using Emgu.Util;

namespace Emgu.CV.Features2D
{
   /// <summary>
   /// Wrapped ORB detector
   /// </summary>
   public class ORBDetector : Feature2D
   {
      /// <summary>
      /// The score type
      /// </summary>
      public enum ScoreType
      {
         /// <summary>
         /// Harris
         /// </summary>
         Harris,
         /// <summary>
         /// Fast
         /// </summary>
         Fast
      }

      /// <summary>
      /// Create a ORBDetector using the specific values
      /// </summary>
      /// <param name="numberOfFeatures">The number of desired features. </param>
      /// <param name="scaleFactor">Coefficient by which we divide the dimensions from one scale pyramid level to the next.</param>
      /// <param name="nLevels">The number of levels in the scale pyramid. </param>
      /// <param name="firstLevel">The level at which the image is given. If 1, that means we will also look at the image.<paramref name="scaleFactor"/> times bigger</param>
      /// <param name="edgeThreshold">How far from the boundary the points should be.</param>
      /// <param name="WTK_A">How many random points are used to produce each cell of the descriptor (2, 3, 4 ...).</param>
      /// <param name="scoreType">Type of the score to use.</param>
      /// <param name="patchSize">Patch size.</param>
      public ORBDetector(int numberOfFeatures = 500, float scaleFactor = 1.2f, int nLevels = 8, int edgeThreshold = 31, int firstLevel = 0, int WTK_A = 2, ScoreType scoreType = ScoreType.Harris, int patchSize = 31)
      {
         _ptr = CvInvoke.CvOrbDetectorCreate(numberOfFeatures, scaleFactor, nLevels, edgeThreshold, firstLevel, WTK_A, scoreType, patchSize, ref _featureDetectorPtr, ref _descriptorExtractorPtr);
      }

      /// <summary>
      /// Release the unmanaged resources associated with this object
      /// </summary>
      protected override void DisposeObject()
      {
         if (_ptr != IntPtr.Zero)
            CvInvoke.CvOrbDetectorRelease(ref _ptr);
         base.DisposeObject();
      }

   }
}

namespace Emgu.CV
{
   public static partial class CvInvoke
   {

      [DllImport(CvInvoke.EXTERN_LIBRARY, CallingConvention = CvInvoke.CvCallingConvention)]
      internal extern static IntPtr CvOrbDetectorCreate(int numberOfFeatures, float scaleFactor, int nLevels, int edgeThreshold, int firstLevel, int WTK_A, Features2D.ORBDetector.ScoreType scoreType, int patchSize, ref IntPtr featureDetector, ref IntPtr descriptorExtractor);

      [DllImport(CvInvoke.EXTERN_LIBRARY, CallingConvention = CvInvoke.CvCallingConvention)]
      internal extern static void CvOrbDetectorRelease(ref IntPtr detector);
   }
}
