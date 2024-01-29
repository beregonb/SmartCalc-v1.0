#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  stack *top = NULL; // Инициализация пустого стека

  // Добавление элемента в стек
  top = push(top, "Hello");

  // Проверка, не пуст ли стек
  if (!isEmpty(top)) {
    // Вывод верхнего элемента стека
    printf("Top element of the stack: %s\n", peek(top));
  } else {
    printf("Stack is empty.\n");
  }

  // Очистка стека
  clear(&top);

  // Освобождение памяти после использования
  destroy(&top);

  return 0;
}
