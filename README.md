DStation
========

DStation is a BSD licensed cross-platform software implementing various image deconvolution methods described in J. S. Lim, “Two-dimensional signal and image processing,”
Prentice Hall, (1990) and other sources.  

DStation is a GUI testbed for various not so well known image deconvolution algorithms. It can be used for various applications, including astronomical image processing. One of the algorithms implemented was developed by me and is based on a MIT handbook by J. S. Lim, “Two-dimensional signal and image processing,” Prentice Hall, (1990). This method is called "Usatov, Atmospheric" in the DStation, and the description how it works is here: 

https://raw.github.com/blackhaz/DStation/master/doc/DStation.pdf 

Here's how it works, in brief:

The algorithm is based on two parts. The first part derives from the work of Lim, please refer to fig. 1 in the PDF linked above. Lim suggested, that the source image F of an object consists of two components: high-frequency signal FH and low-frequency signal FL. If each of those components (in the frequency domain) is multiplied by some degrading/blurring function B, we will get an obtained degraded image G - that is equation 3. With that, the low-frequency signal FL is a smooth function. Now, pass all sides of this equation through a blurring filter S that could be a median filter, or simple average blur. The smoothing filter S will smooth out the high-frequency component, however will leave low-frequency signal nearly intact - at some parameters of S. If we know what FL consists of, we can use equation 6 to derive the blurring function B, which is one of the methods of blind deconvolution. There are a few ways to find FL. One of them would be to take a similar image, or an image with desired MTF, and use that as a reference to recreate B. This method is described by Lim and is available in DStation as "Lim (Reference Image)". That is, you use a 3rd party reference image to restore your degraded image obtained from telescope. One of the usage examples could be to use an image of a Mandelbrot fractal and use it as a reference to deconvolve astronomical images - which gives funny results. 

My contribution to this part becomes a method of obtaining FL through a soft-knee compressor function, which is usually used in audio industry. With that, smoothed degraded image S[|G|] is passed through the compressor to obtain FL (equation 10). This derives another method of blind deconvolution, and the method is implemented in DStation and called "Usatov". 

The second part of the algorithm is based on Fried's work on atmospheric turbulence modeling. On this step, DStation builds an MTF of assumed atmospheric degradation (equation 12), based on the D and F of the telescope, wavelength and r0 - Fried's parameter. (I will not describe Fried's model in this post as it is somewhat outside of the scope, however I'd be happy to discuss this further.) If you take a geometric mean between the atmospheric degradation and the first, blind part (equation 13) we will derive my method. The PDF has a few examples of deconvolution for my lunar image obtained with 10" MCT. Additionally, the software distribution will have fantastic images of Jupiter, obtained by Jean-Luc Dauvergne at Pic Du Midi observatory, as well as DStation preset so you could see the algorithm in action. 

Algorithm workflow is described here: 

https://github.com/blackhaz/DStation/blob/master/doc/Algorithm%20Workflow.pdf 


- Works on any operating systems where you can get ImageMagick: FreeBSD, Linux, Windows and OSX.
- Some additional deconvolution algorithms:Atmospheric MTF (deconvolution with atmospheric MTF only) and External Filter (deconvolution with external loadable filter). 
- Various deconvolution processes: Wiener, Constrained Least Squares (CLS), Schaefer Inverse Filter, Van Cittert, Sine Relaxed Lucy Richardson, Maximum A Posteriori (MAP), Regularized Lucy-Richardson, Schaefer with external frequency equalizer, and Landweber. (All is written from scratch, so there could be some bugs.)
- Anti-artifact buffers.
- Works with 16 and 32-bit images.
- Basic post-processing: normalization, brightness/contrast. Histogram, statistics, supersampling with ability to configure filters individually for up- and downsampling.
- Batch processing - useful for mosaics.
- Blinking. 


This is spaghetti, prototype code. If somebody can help to work on this - please contact me. DStation uses ImageMagick library to work with graphical image formats (TIFF, PNG, etc). 


Jupiter from Pic Du Midi and DStation preset: 
=============================================

https://github.com/blackhaz/DStation/blob/master/doc/Jupiter_Pic_Du_Midi.zip?... 
(Note: this is a different Jupiter than what is supplied with the Windows build!) 

Quick HOWTO: 

- Launch DStation. 
- In File menu, Open Image and open the FITS file with Jupiter source image. 
- In Preset menu, Open Preset and open the D file with DStation preset. 
- Click on Deconvolve button. 

For blinking, click and hold the Blink button. 

Here is a quick description of Primary preset settings: 

Wavelength: wavelength this image was taken in, 550 nm. 
Objective Diameter: 1000 mm (1-meter telescope on Pic Du Midi). 
Objective Focal Length: 20000 mm 
Focal Length Multiplier: 1.0 (without Barlow lens, focal length as is) 
CCD Pixel Size: 4.65 microns 
Filter Size: 10 pixels (size of the smoothing filter S, derived experimentally) 
Fried's r0 Parameter: 400mm (derived experimentally) 
Noise Estimation: 0.30 (noise level, derived experimentally) 
Compression Ratio: 0.94 (r of the compressor, derived experimentally - see eq. 10 in the DStation.pdf, as well as Algorithm Workflow PDF) 

This preset uses Wiener as the filtering method, and Usatov, Atmospheric as the deconvolution algorithm. 
