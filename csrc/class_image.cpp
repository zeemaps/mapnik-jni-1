/*
 * Class:     mapnik_Image
 * Method:    alloc
 * Signature: (II)J
 */
JNIEXPORT jlong JNICALL Java_mapnik_Image_alloc__II
  (JNIEnv *env, jclass c, jint width, jint height)
{
	mapnik::image_32* im=new mapnik::image_32(width, height);
	return FROM_POINTER(im);
}

/*
 * Class:     mapnik_Image
 * Method:    alloc
 * Signature: (Lmapnik/Image;)J
 */
JNIEXPORT jlong JNICALL Java_mapnik_Image_alloc__Lmapnik_Image_2
  (JNIEnv *env, jclass c, jobject iobjother)
{
	PREAMBLE;
	if (!iobjother) {
		throw_runtime_exception(env, "Image cannot be null in call to constructor");
		return 0;
	}
	mapnik::image_32* other=LOAD_IMAGE_POINTER(iobjother);

	mapnik::image_32* im=new mapnik::image_32(*other);
	return FROM_POINTER(im);

	TRAILER(0);
}

/*
 * Class:     mapnik_Image
 * Method:    dealloc
 * Signature: (J)J
 */
JNIEXPORT void JNICALL Java_mapnik_Image_dealloc
  (JNIEnv * env, jclass c, jlong ptr)
{
	mapnik::image_32* im=static_cast<mapnik::image_32*>(TO_POINTER(ptr));
	if (im) {
		delete im;
	}
}

/*
 * Class:     mapnik_Image
 * Method:    getWidth
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_mapnik_Image_getWidth
  (JNIEnv *env, jobject imobj)
{
	PREAMBLE;
	mapnik::image_32* im=LOAD_IMAGE_POINTER(imobj);
	return im->width();
	TRAILER(0);
}

/*
 * Class:     mapnik_Image
 * Method:    getHeight
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_mapnik_Image_getHeight
(JNIEnv *env, jobject imobj)
{
	PREAMBLE;
	mapnik::image_32* im=LOAD_IMAGE_POINTER(imobj);
	return im->height();
	TRAILER(0);
}

/*
 * Class:     mapnik_Image
 * Method:    saveToFile
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_mapnik_Image_saveToFile
  (JNIEnv *env, jobject imobj, jstring filenamej, jstring typej)
{
	PREAMBLE;
	mapnik::image_32* im=LOAD_IMAGE_POINTER(imobj);
	refjavastring filename(env, filenamej);
	refjavastring type(env, typej);

	mapnik::save_to_file<mapnik::image_data_32>(im->data(), filename.stringz, type.stringz);
	TRAILER_VOID;
}