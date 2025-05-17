// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool lampFactor) {
  Car* newCar = new Car{lampFactor, nullptr, nullptr};

  if (first == nullptr) {
    newCar->next = newCar;
    newCar->prev = newCar;
    first = newCar;
  } else {
    Car* lastCar = first->prev;
    newCar->next = first;
    newCar->prev = lastCar;
    lastCar->next = newCar;
    first->prev = newCar;
  }
}

int Train::getLength() {
  countOp = 0;
  if (first == nullptr) {
    return 0;
  }

  Car* crnt = first;
  crnt->light = true;

  while (true) {
    int countOfSteps = 0;

    do {
      crnt = crnt->next;
      countOfSteps++;
      countOp++;
    } while (!crnt->light);

    crnt->light = false;

    for (int i = 0; i < countOfSteps; i++) {
      crnt = crnt->prev;
      countOp++;
    }

    if (!crnt->light) {
      return countOfSteps;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
