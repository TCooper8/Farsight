

namespace Farsight
{
	struct TGAFileHeader
	{
		unsigned char idLength;
		unsigned char colorMapType;
		unsigned char imageTypeCode;
		unsigned char colorMapSpec[5];
		unsigned short xOrigin;
		unsigned short yOrigin;
		unsigned short width;
		unsigned short height;
		unsigned char bpp;
		unsigned char imageDesc;
	};
};