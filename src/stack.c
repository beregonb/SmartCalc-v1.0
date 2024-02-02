#include "stack.h"

/**
 * @brief Добавление элемента в стек
 *
 * @param top
 * @param c
 * @return stack*
 */
stack *push(stack *top, const char *c) {
    stack *new = malloc(sizeof(stack));
    if (new == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    new->str = strdup(c);  // Создаем копию строки
    if (new->str == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    new->next = top;
    return new;
}
/**
 * @brief Удалдение верхнего элемента стека
 *
 * @param top
 * @return stack*
 */
stack *pop(stack *top) {
  if (top == NULL) {
    return top;
  }
  printf("Del: - %s\n", top->str);
  stack *new_top = top->next;
  free(top);

  return new_top;
}

/**
 * @brief Отображение верхнего элемента стека
 *
 * @param top
 * @return char*
 */
char *peek(const stack *top) {
  if (top == NULL) {
    fprintf(stderr, "Error: The stack is empty.\n");
    return NULL;
  }

  return top->str;
}
/**
 * @brief Проверка стека на пустоту
 *
 * @param top
 * @return int
 */
int isEmpty(const stack *top) {
  if (top == NULL) {
    return 1;
  }
  return 0;
}

/**
 * @brief Очистка стека
 *
 * @param top
 */
void clear(stack **top) {
  while (!isEmpty(*top)) {
    *top = pop(*top);
  }
}

/**
 * @brief Удаление стека
 *
 * @param top
 */
void destroy(stack **top) {
  clear(top);
  free(*top);
  *top = NULL;
}
