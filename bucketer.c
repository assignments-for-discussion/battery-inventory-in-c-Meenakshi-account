#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
    for (int i = 0; i < nBatteries; i++) {
    double soh = (double)presentCapacities[i] / 120.0 * 100.0; // Calculate SoH as a percentage

    if (soh > 80.0 && soh <= 100.0) {
      counts.healthy++;
    } else if (soh >= 65.0 && soh <= 80.0) {
      counts.exchange++;
    } else {
      counts.failed++;
    }
  }

  return counts;
}

int main() {
  // Example battery capacities
  int capacities[] = {110, 100, 90, 70, 50};
  int numBatteries = sizeof(capacities) / sizeof(capacities[0]);

  struct CountsBySoH result = countBatteriesByHealth(capacities, numBatteries);

  // Asserts to check the counts
  assert(result.healthy == 3);
  assert(result.exchange == 1);
  assert(result.failed == 1);
  // Add more asserts if needed

  return 0;
}
In this code, the countBatteriesByHealth function takes an array of present capacities and the number of batteries as input. It iterates through the batteries, calculates their SoH as a percentage, and classifies them based on the given criteria. The counts are stored in the struct CountsBySoH structure, and this structure is returned from the function.

In the main function, an example array of battery capacities is provided, and the countBatteriesByHealth function is called to count and classify the batteries. Asserts are used to check the counts, ensuring that the implementation is correct. You can add more test cases or asserts as needed.






  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {115, 118, 80, 95, 91, 77};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
