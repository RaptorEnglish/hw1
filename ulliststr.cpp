#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

// MY IMPLEMENTATIONS

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // get item index
  loc += this->head_->first;
  size_t item_index = loc / ARRSIZE;
  size_t str_index = loc % ARRSIZE;

  // find head val
  Item* item = this->head_;
  for (size_t i = 0; i < item_index; i++) {
    item = item->next;

    // exit if out of bounds
    if (item == nullptr) {
      return NULL;
    };
  }

  // check size
  if (item->last < str_index) {
    return NULL;
  }

  // get val
  std::string* val = &item->val[str_index];
  return val;
}

void ULListStr::push_back(const std::string& val) {

  // create new item if blank (base case)
  if (this->tail_ == nullptr) {
    Item* new_node = new Item();
    this->head_ = new_node;
    this->tail_ = new_node;
  }

  // new node if tail full
  if (tail_->last >= ARRSIZE) {
    Item* new_node = new Item();
    new_node->prev = this->tail_;
    tail_->next = new_node;
    tail_ = new_node;

    // add first node
    tail_->val[tail_->last] = val;

  } else {
    tail_->val[tail_->last] = val;
  }

  // increment size
  tail_->last++;
  size_++;
}

void ULListStr::pop_back() {
  // quit if emtpy
  if (empty()) {
    return;
  }

  // remove last val from tail
  tail_->val[tail_->last - 1] = "";
  tail_->last--;
  size_--;

  // remove tail if empty
  if (tail_->last == 0) {
    Item* temp = tail_;
    tail_ = tail_->prev;

    // adjust pointers
    if (tail_) {
      tail_->next = nullptr;
    } else {
      head_ = nullptr;
    }

    delete temp;
  }
}

void ULListStr::push_front(const std::string& val) {
  // create new node if none exists
  if (head_ == nullptr) {
    Item* new_node = new Item();
    head_ = new_node;
    tail_ = new_node;
  }

  // create new node if head is full
  if (head_->first == 0 && head_->last == 0) {  // insert at end of first node
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
  } else if (head_->first == 0 && head_->last != 0) { // create new node
    Item* new_node = new Item();
    new_node->next = head_;
    head_->prev = new_node;
    head_ = new_node;

    // set start and end
    new_node->first = ARRSIZE - 1;
    new_node->last = ARRSIZE;

  } else {  // space in front of list from pops
    head_->first--;
  }

  // add val to last item in array
  head_->val[head_->first] = val;
  size_++;
  return;

}

void ULListStr::print_head()  {
  for (int i = 0; i < ARRSIZE; i++) {
    std::cout << this->head_->val[i] << std::endl;
  }
}

void ULListStr::print_tail()  {
  for (int i = 0; i < ARRSIZE; i++) {
    std::cout << tail_->val[i] << std::endl;
  }
}

std::string const & ULListStr::front() const {
  if (empty()) {
    return NULL;
  }
  return head_->val[head_->first]; // Return the first occupied element
}

std::string const & ULListStr::back() const {
  std::cout<<tail_->last<<std::endl;
  if (empty()) {
    return NULL;
  }
  return tail_->val[tail_->last-1]; // Return the last element
}

void ULListStr::pop_front() {
  // must have values to pop
  if (empty()) {
    return;
  }

  // remove value from front
  head_->val[head_->first] = "";
  head_->first++;

  // remove node if empty
  if (head_->first == ARRSIZE) {
    Item* temp = head_;
    head_ = head_->next;

    // adjust pointers
    if (head_) {
      head_->prev = nullptr;
    } else {
      head_ = nullptr;
    }

    delete temp;

  }

  // update size
  size_--;

};
