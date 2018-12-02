#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "assert.h"
#include "lab03.h"

GraphicCard::GraphicCard()
{
  model = NULL;
  VideoMemory = 0;
  GPU_Frequency = 0;
  VideoMemoryFrequency = 0;
  Array = NULL;
  TypeOfVideoMemory = NULL;
}
GraphicCard::GraphicCard(const GraphicCard &copy)
{
  model = new char[sizeof(copy.model) / sizeof(char)];
  assert(model != 0);
  strcpy(model, copy.model);
  VideoMemory = copy.VideoMemory;
  GPU_Frequency = copy.GPU_Frequency;
  VideoMemoryFrequency = copy.VideoMemoryFrequency;
  Array = new int[sizeof(copy.Array) / sizeof(int)];
  assert(model != 0);
  for (int i = 0; i < sizeof(copy.Array) / sizeof(int); i++)
  {
    Array[i] = copy.Array[i];
  }
}
GraphicCard::GraphicCard(char *mod, int mem, char* TypeOfVideoMemory, int gpufreq, int memfreq, int *arr) : model(mod), VideoMemory(mem), GPU_Frequency(gpufreq), VideoMemoryFrequency(memfreq), Array(arr) {}

void GraphicCard::InitAll()
{
  this->status = true;

  std::cin.clear();
  std::cin.ignore(std::cin.rdbuf()->in_avail());

  this->model = new char[255];
  assert(model != 0);
  std::cout << std::endl;
  do
  {
    std::cout << "Enter the model of Graphic Card: ";
    std::cin.getline(model, 255);
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::cin.rdbuf()->in_avail());
      std::cout << "Invalid format! Try again!" << std::endl;
    }
    else
    {
      this->control = true;
    }

    std::cout << "Enter the video memory size: ";
    std::cin >> this->VideoMemory;
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::cin.rdbuf()->in_avail());
      std::cout << "Invalid format! Try again!" << std::endl;
    }
    else
    {
      this->control = true;
    }
    short int type = 0;
    do {

      std::cout << "Enter the type of video memory (1 - GDDR, 2 - GDDR2, 3 - GDDR3, 4 - GDDR4, 5 - GDDR5): ";
      std::cin >> type;
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        std::cout << "Invalid format! Try again!" << std::endl;
      }

      switch (type)
      {
      case 1: this->TypeOfVideoMemory = new char[5]; strcpy(this->TypeOfVideoMemory, "GDDR"); break;
      case 2: this->TypeOfVideoMemory = new char[6]; strcpy(this->TypeOfVideoMemory, "GDDR2"); break;
      case 3: this->TypeOfVideoMemory = new char[6]; strcpy(this->TypeOfVideoMemory, "GDDR3"); break;
      case 4: this->TypeOfVideoMemory = new char[6]; strcpy(this->TypeOfVideoMemory, "GDDR4"); break;
      case 5: this->TypeOfVideoMemory = new char[6]; strcpy(this->TypeOfVideoMemory, "GDDR5"); break;
      default:  std::cout << "Invalid format! Try again!" << std::endl;
      }
    } while (type == 0);
    std::cout << "Enter the GPU frequency: ";
    std::cin >> this->GPU_Frequency;
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::cin.rdbuf()->in_avail());
      std::cout << "Invalid format! Try again!" << std::endl;
    }
    else
    {
      this->control = true;
    }

    std::cout << "Enter the video memory frequency: ";
    std::cin >> this->VideoMemoryFrequency;
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::cin.rdbuf()->in_avail());
      std::cout << "Invalid format! Try again!" << std::endl;
    }
    else
    {
      this->control = true;
    }
  } while (!this->control);


}

void GraphicCard::ShowMainMenu() {
  short int ind;

  std::cout << "Main menu" << std::endl << std::endl;
  std::cout << "0 - Exit" << std::endl;
  std::cout << "1 - Enter the data" << std::endl;
  if (this->status) {
    std::cout << "2 - Output data" << std::endl;
  }

  do {
    std::cout << "Your choice: ";
    std::cin >> ind;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::cin.rdbuf()->in_avail());
      std::cout << "Invalid format! Try again!" << std::endl;
    }
    else { this->control = true; }
  } while (!this->control);
  this->control = false;


  switch (ind)
  {
  case 0:
    exit(0);
  case 1:
    this->InitAll();  break;
  case 2:
    if (this->status) { this->DataOutput(); }
    else { std::cout << "Incorrect button. Try again." << std::endl; }
    break;
  default:
    std::cout << "Incorrect button. Try again." << std::endl; break;
  }
  this->control = true;
}
void GraphicCard::DataOutput()
{
  std::cout << std::endl << "\xDA";
  for (int i = 1; i <= 23; i++) std::cout << "\xC4"; std::cout << "\xC2";
  for (int i = 1; i <= 30; i++) std::cout << "\xC4"; std::cout << "\xBF" << std::endl;
  std::cout << std::fixed << "\xB3" << std::setw(22) << "Model" << " \xB3" << std::setw(28) << this->model << "  \xB3" << std::endl;
  std::cout << "\xC3";
  for (int i = 0; i < 23; i++) std::cout << "\xC4"; std::cout << "\xC5";
  for (int i = 0; i < 30; i++) std::cout << "\xC4"; std::cout << "\xB4" << std::endl;
  std::cout << std::fixed << "\xB3" << std::setw(22) << "Video memory" << " \xB3" << std::setw(27) << this->VideoMemory << "MB \xB3" << std::endl;
  std::cout << "\xC3";
  for (int i = 0; i < 23; i++) std::cout << "\xC4"; std::cout << "\xC5";
  for (int i = 0; i < 30; i++) std::cout << "\xC4"; std::cout << "\xB4" << std::endl;
  std::cout << std::fixed << "\xB3" << std::setw(22) << "Type of video memory" << " \xB3" << std::setw(28) << this->TypeOfVideoMemory << "  \xB3" << std::endl;
  std::cout << "\xC3";
  for (int i = 0; i < 23; i++) std::cout << "\xC4"; std::cout << "\xC5";
  for (int i = 0; i < 30; i++) std::cout << "\xC4"; std::cout << "\xB4" << std::endl;
  std::cout << std::fixed << "\xB3" << std::setw(22) << "GPU frequency" << " \xB3" << std::setw(26) << this->GPU_Frequency << "MHz \xB3" << std::endl;
  std::cout << "\xC3";
  for (int i = 0; i < 23; i++) std::cout << "\xC4"; std::cout << "\xC5";
  for (int i = 0; i < 30; i++) std::cout << "\xC4"; std::cout << "\xB4" << std::endl;
  std::cout << std::fixed << "\xB3" << std::setw(22) << "Video memory frequency" << " \xB3" << std::setw(26) << this->VideoMemoryFrequency << "MHz \xB3" << std::endl;
  std::cout << "\xC0";
  for (int i = 1; i <= 23; i++) std::cout << "\xC4"; std::cout << "\xC1";
  for (int i = 1; i <= 30; i++) std::cout << "\xC4"; std::cout << "\xD9" << std::endl;
}
char* GraphicCard::getModel()
{
  return model;
}
int GraphicCard::getVideoMemory()
{
  return VideoMemory;
}
int GraphicCard::getGPU_Frequency()
{
  return GPU_Frequency;
}
bool GraphicCard::getControl()
{
  return control;
}
char* GraphicCard::getTypeOFVideoMemory()
{
  return TypeOfVideoMemory;
}
int GraphicCard::getVideoMemoryFrequency()
{
  return VideoMemoryFrequency;
}
int* GraphicCard::getArray()
{
  return Array;
}

void GraphicCard::ArrayInit(int* arr)
{
  int size;
  std::cout << "Enter size of Array: " << std::endl;
  std::cin >> size;
  if (size > 0)
  {
    arr = new int[size];
  }
}

GraphicCard GraphicCard::operator+(GraphicCard &obj)
{
  GraphicCard res;
  res.VideoMemory = this->VideoMemory + obj.VideoMemory;
  res.GPU_Frequency = this->GPU_Frequency + obj.GPU_Frequency;
  res.VideoMemoryFrequency = this->VideoMemoryFrequency + obj.VideoMemoryFrequency;
  return res;
}
bool GraphicCard::operator>(const GraphicCard &obj) const
{
  return ((VideoMemory > obj.VideoMemory) && (GPU_Frequency > obj.GPU_Frequency) && (VideoMemoryFrequency > obj.VideoMemoryFrequency));
}

bool GraphicCard::operator<(GraphicCard &obj) const
{
  return ((VideoMemory < obj.VideoMemory) && (GPU_Frequency < obj.GPU_Frequency) && (VideoMemoryFrequency < obj.VideoMemoryFrequency));
}

GraphicCard::operator int() const
{
  return VideoMemory;
}
GraphicCard::operator char*() const
{
  return model;
}
GraphicCard::~GraphicCard()
{
  delete[] model;
  delete[] Array;
  delete[] TypeOfVideoMemory;
}