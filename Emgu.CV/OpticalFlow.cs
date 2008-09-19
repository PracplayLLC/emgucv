using System;
using System.Collections.Generic;
using System.Text;

namespace Emgu.CV
{
   public class OpticalFlow
   {
      public static void PyrLK(
         Image<Gray, Byte> prev,
         Image<Gray, Byte> curr,
         Point2D<float>[] prevFeatures,
         MCvSize winSize,
         int level,
         MCvTermCriteria criteria,
         out Point2D<float>[] currFeatures,
         out Byte[] status,
         out float[] trackError)
      {
         PyrLK(prev, curr, null, null, prevFeatures, winSize, level, criteria, Emgu.CV.CvEnum.LKFLOW_TYPE.DEFAULT, out currFeatures, out status, out trackError);
      }

      /// <summary>
      /// Calculates optical flow for a sparse feature set using iterative Lucas-Kanade method in pyramids
      /// </summary>
      /// <param name="prev">First frame, at time t</param>
      /// <param name="curr">Second frame, at time t + dt </param>
      /// <param name="prevPyrBuffer">Buffer for the pyramid for the first frame. If the pointer is not NULL , the buffer must have a sufficient size to store the pyramid from level 1 to level #level ; the total size of (image_width+8)*image_height/3 bytes is sufficient</param>
      /// <param name="currPyrBuffer">Similar to prev_pyr, used for the second frame</param>
      /// <param name="prevFeatures">Array of points for which the flow needs to be found</param>
      /// <param name="winSize">Size of the search window of each pyramid level</param>
      /// <param name="level">Maximal pyramid level number. If 0 , pyramids are not used (single level), if 1 , two levels are used, etc</param>
      /// <param name="criteria">Specifies when the iteration process of finding the flow for each point on each pyramid level should be stopped</param>
      /// <param name="flags">Flags</param>
      /// <param name="currFeatures">Array of 2D points containing calculated new positions of input features in the second image</param>
      /// <param name="status">Array. Every element of the array is set to 1 if the flow for the corresponding feature has been found, 0 otherwise</param>
      /// <param name="trackError">Array of double numbers containing difference between patches around the original and moved points</param>
      public static void PyrLK(
         Image<Gray, Byte> prev,
         Image<Gray, Byte> curr,
         Image<Gray, Byte> prevPyrBuffer,
         Image<Gray, Byte> currPyrBuffer,
         Point2D<float>[] prevFeatures,
         MCvSize winSize,
         int level,
         MCvTermCriteria criteria,
         Emgu.CV.CvEnum.LKFLOW_TYPE flags,
         out Point2D<float>[] currFeatures,
         out Byte[] status,
         out float[] trackError)
      {
         if (prevPyrBuffer == null)
         {
            prevPyrBuffer = new Image<Gray, byte>(prev.Width + 8, prev.Height / 3);
         }
         if (currPyrBuffer == null)
         {
            currPyrBuffer = prevPyrBuffer.CopyBlank();
         }

         currFeatures = new Point2D<float>[prevFeatures.Length];
         status = new Byte[prevFeatures.Length];
         trackError = new float[prevFeatures.Length];

         float[,] prevLocation = PointCollection.ToArray<float>(prevFeatures);
         float[,] currLocation = new float[currFeatures.Length, 2];

         CvInvoke.cvCalcOpticalFlowPyrLK(
            prev,
            curr,
            prevPyrBuffer,
            currPyrBuffer,
            prevLocation,
            currLocation,
            prevFeatures.Length,
            winSize,
            level,
            status,
            trackError,
            criteria,
            flags);

         currFeatures = PointCollection.FromArray<float>(currLocation); 
      }
   }
}
