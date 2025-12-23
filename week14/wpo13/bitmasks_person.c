// https://dodona.be/en/courses/5451/series/63970/activities/535559699
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef enum {
  SINGLE, COHABITATING, MARRIED, WIDOW
} Marital_Status;
typedef enum {
  PRIMARY, SECONDARY, ACADEMIC_BACHELOR, PROFESSIONAL_BACHELOR, MASTER
} Highest_Education_Level;
typedef enum {
  BRUSSELS, FLANDERS, WALLONIA
} Region;

typedef struct person {
  uint8_t age;
  Marital_Status marital_status;
  Highest_Education_Level highest_education;
  uint8_t employment_status;
  Region region;
} Person;

uint16_t encode_person(Person p) {
  uint16_t shifted_age = p.age << 8;
  uint16_t shifted_marital_status = p.marital_status << 6;
  uint16_t shifted_highest_education = p.highest_education << 3;
  uint16_t shifted_employment_status = p.employment_status << 2;
  uint16_t encoded = shifted_age | shifted_marital_status | shifted_highest_education | shifted_employment_status | p.region;


  return encoded;
}

Person decode_person(uint16_t encoded) {
  uint16_t bitmask_age = 0b1111111100000000;
  uint16_t shifted_age = encoded & bitmask_age;
  uint16_t age = shifted_age >> 8;

  uint16_t bitmask_marital_status = 0b0000000011000000;
  uint16_t shifted_marital_status = encoded & bitmask_marital_status;
  uint16_t marital_status = shifted_marital_status >> 6;

  uint16_t bitmask_highest_education = 0b0000000000111000;
  uint16_t shifted_highest_education = encoded & bitmask_highest_education;
  uint16_t highest_education = shifted_highest_education >> 3;

  uint16_t bitmask_employment_status = 0b0000000000000100;
  uint16_t shifted_employment_status = encoded & bitmask_employment_status;
  uint16_t employment_status = shifted_employment_status >> 2;

  uint16_t bitmask_region = 0b0000000000000011;
  uint16_t region = encoded & bitmask_region;

  return (Person){age, marital_status, highest_education, employment_status, region};
}