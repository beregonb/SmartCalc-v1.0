#include "stack.h"

/**
 * @brief Добавление элемента (строка) в стек
 *
 * @param top
 * @param c
 * @return stack*
 */
stack *push(stack *top, const char *c) {
  stack *new = malloc(sizeof(stack));
  if (new == NULL) {
    fprintf(stderr, "Memory allocation error in push.\n");
    exit(EXIT_FAILURE);
  }

  new->str = strdup(c);
  if (new->str == NULL) {
    fprintf(stderr, "Memory allocation error in strdup.\n");
    free(new);  // Освобождаем новый узел перед выходом
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
    free_stack_top(&top);
    return top;
}

/**
 * @brief Отображение верхнего элемента стека (строки)
 *
 * @param top
 * @return char*
 */
char *peek(const stack *top) {
  if (top == NULL) {
    fprintf(stderr, "Стек пуст.\n");
    return NULL;
  }

  return top->str;
}

/**
 * @brief Проверка стека на пустоту
 *
 * @param top
 * @return 1 - пустой, 0 - не пустой
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

void free_stack_top(stack **top) {
    if (*top != NULL) {
        stack *temp = *top;
        *top = (*top)->next;
        free(temp->str);  // Освобождаем память для строки
        free(temp);       // Освобождаем узел
    }
}