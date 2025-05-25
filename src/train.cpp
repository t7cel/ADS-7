// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : head(nullptr), operationCount(0) {}

void Train::addCar(bool initialLightState) {
  Car* newCar = new Car{initialLightState, nullptr, nullptr};

  if (head == nullptr) {
    newCar->next = newCar;
    newCar->prev = newCar;
    head = newCar;
  } else {
    Car* lastCar = head->prev;
    newCar->next = head;
    newCar->prev = lastCar;
    lastCar->next = newCar;
    head->prev = newCar;
  }
}

int Train::getLength() {
  operationCount = 0;
  if (head == nullptr) {
    return 0;
  }

  Car* currentCar = head;
  currentCar->light = true;

  while (true) {
    int countOfSteps = 0;

    do {
      currentCar = currentCar->next;
      countOfSteps++;
      operationCount++;
    } while (!currentCar->light);

    currentCar->light = false;

    for (int i = 0; i < countOfSteps; i++) {
      currentCar = currentCar->prev;
      operationCount++;
    }

    if (!currentCar->light) {
      return countOfSteps;
    }
  }
}

int Train::getOpCount() {
  return operationCount;
}
