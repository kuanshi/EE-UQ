#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
//using namespace std

#include <jansson.h>  // for Json

int main(int argc, const char **argv)
{
  const char *filenameEDP = argv[1];
  const char *filenameOUT = argv[2];

  std::ofstream fOut(filenameOUT);

  json_error_t error;
  json_t *root = json_load_file(filenameEDP, 0, &error);
  json_t *eventsArray = json_object_get(root,"EngineeringDemandParameters");  

  int index1, index2;
  json_t *value1, *value2;

  int numEDP = 0;

  json_array_foreach(eventsArray, index1, value1) {
    json_t *responsesArray = json_object_get(value1,"responses");  
    if (responsesArray != NULL) {
      json_array_foreach(responsesArray, index2, value2) {
	json_t *sType = json_object_get(value2,"scalar_data");
	int numValues = json_array_size(sType);
	for (int i=0; i<numValues; i++) {
	  double value = json_number_value(json_array_get(sType,i));
	  printf("%f ", value);
	  fOut << value << " ";
	  numEDP++;
	}
      }
    }
    responsesArray = json_object_get(value1,"userSpecificResponses");  
    if (responsesArray != NULL) {
      json_array_foreach(responsesArray, index2, value2) {
	json_t *sType = json_object_get(value2,"scalar_data");
	int numValues = json_array_size(sType);
	for (int i=0; i<numValues; i++) {
	  double value = json_number_value(json_array_get(sType,i));
	  printf("%f ", value);
	  fOut << value << " ";
	  numEDP++;
	}
      }
    }

  }
  printf("NUM_EDP= %d\n",numEDP);

  fOut.close();

  return 0;
}

