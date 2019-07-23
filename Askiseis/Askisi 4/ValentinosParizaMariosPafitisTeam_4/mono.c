/**
 *  Program: wavengine  Copyright (C) 2018  Marios Pafitis & Valentinos Pariza
 *  This program comes with ABSOLUTELY NO WARRANTY;
 *  This is free software, and you are welcome to redistribute it under certain
 *  conditions;
 *  @file mono.c
 *  @brief Convert a stereo to mono .wav file
 *
 *  Implements the mono method in .wav files that it receives as input. It takes as input a
 *  .wav file and checks if the file is a stereo audio file. Then it converts the stereo
 *  to mono by keeping only the left channel of the audio. It reduces the size of
 *  the audio file by half. It creates an output file that it has the form of
 *  "new-" + filename + ".wav" and it saves it in the path folder of the input filename.
 *
 *  @version 1.0
 *  @author Marios Pafitis
 *  @bugs No known bugs
 */
#include "utilities.h"

PUBLIC int mono(char *inFilename) {
// Create output filename
	char *outFilename = NULL;
	if (createOutputFilename(inFilename, "new-", &outFilename) == EXIT_FAILURE) {
		if (outFilename != NULL) {
			free(outFilename);
		}
		printf("Fail    :  %s\t(Can't create output filename)\n", inFilename);
		return EXIT_FAILURE;
	}
// Read Wav
	WAV *wav_old = NULL;
	if (readWAV(inFilename, &wav_old) == EXIT_FAILURE) {
		free(outFilename);
		printf("Fail    :  %s\t(Can't read WAV file)\n", inFilename);
		return EXIT_FAILURE;
	}
// Check the format of the file
	if (!isCorrectFormatWAV(wav_old)) {
		deleteWAV(&wav_old);
		free(outFilename);
		printf("Fail    :  %s\t(This is not a correct .wav)\n", inFilename);
		return EXIT_FAILURE;
	}
	if (wav_old->header->NumChannels == 1) {
		printf("Fail    :  %s\t(This is not a stereo .wav)\n", inFilename);
		deleteWAV(&wav_old);
		free(outFilename);
		return EXIT_FAILURE;
	}
// Create new Wav and copy data
	WAV *wav_new = (WAV*) malloc(sizeof(WAV));
	wav_new->header = (HEADER*) malloc(sizeof(HEADER));
	wav_new->data = (DATA*) malloc(sizeof(DATA));
	wav_new->data->channel = (byte*) malloc(wav_old->header->Subchunk2Size);
	unsigned int i;
	for (i = 0; i < wav_old->header->Subchunk2Size;
			i += 2 * (wav_old->header->BitsPerSample / 8)) {
		memcpy(
				&wav_new->data->channel[i / (wav_old->header->BitsPerSample / 8)],
				&wav_old->data->channel[i], wav_old->header->BitsPerSample);
	}
	strcpy((char *) wav_new->header->ChunkID,
			(char *) wav_old->header->ChunkID);
	strcpy((char *) wav_new->header->Format, (char *) wav_old->header->Format);
	strcpy((char *) wav_new->header->Subchunk2ID,
			(char *) wav_old->header->Subchunk2ID);
	wav_new->header->ChunkSize = wav_old->header->ChunkSize
			- wav_old->header->Subchunk2Size / 2;
	wav_new->header->Subchunk1Size = wav_old->header->Subchunk1Size;
	wav_new->header->AudioFormat = wav_old->header->AudioFormat;
	wav_new->header->NumChannels = 1;
	wav_new->header->SampleRate = wav_old->header->SampleRate;
	wav_new->header->ByteRate = wav_old->header->SampleRate
			* wav_old->header->NumChannels
			* (wav_old->header->BitsPerSample / 8);
	wav_new->header->BlockAlign = wav_old->header->NumChannels
			* (wav_old->header->BitsPerSample / 8);
	wav_new->header->BitsPerSample = wav_old->header->BitsPerSample;
	wav_new->header->Subchunk2Size = wav_old->header->Subchunk2Size / 2;
// Write data
	writeWAV(outFilename, wav_new);
	printf("Success :  %s\t(Created)\n", outFilename);
// Free mallocs
	free(outFilename);
	deleteWAV(&wav_old);
	deleteWAV(&wav_new);
	return EXIT_SUCCESS;
}
#ifdef DEBUG_VOLUME
// Test volume
int main(int argc, char* argv[]) {
	if (strcmp(argv[1], "-mono") == 0) {
		for (i = 2; i < argc; i++) {
			if (mono(argv[i]) == EXIT_FAILURE) {
				printf("This is not a compatible .wav audio file.\n");
				return EXIT_FAILURE;
			}
		}
	}
	return 0;
}
#endif
