# 🐼 Cuddle - DataFrame Library

Welcome to the Cuddle project! This is a C library for data manipulation and analysis, inspired by Python's pandas library. Cuddle allows users to parse CSV data, manipulate dataframes, and prepare information for AI and machine learning applications.

## 📁 Project Structure

```
cuddle
├── src
│   ├── main.c
│   ├── command
│   │   ├── describe.c
│   │   ├── filter.c
│   │   ├── head.c
│   │   ├── tail.c
│   │   ├── sorting.c
│   │   └── copy_head_value.c
│   ├── dataframe
│   │   ├── dataframe.c
│   │   ├── parser.c
│   │   ├── memory.c
│   │   └── utils.c
│   └── operations
│       ├── math_ops.c
│       ├── string_ops.c
│       └── type_conversion.c
├── include
│   └── dataframe.h
├── tests
│   └── test_dataframe.c
├── Makefile
└── README.md
```

## 🚀 Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Building the Project

To build the project, run the following command:

```sh
make
```

This will compile the source files and generate the `cuddle` library.

### Running Tests

To run the test suite, execute:

```sh
make tests_run
```

## 📚 Library Commands

### DataFrame Creation and Basic Operations

- **df_create**: Create a new dataframe from a CSV file.
- **df_free**: Free all memory allocated for a dataframe.
- **df_display**: Print a formatted view of the dataframe.
- **df_get_value**: Retrieve a value from a specific cell in the dataframe.

### Data Selection Commands

- **df_head**: Return a new dataframe with the first N rows of the original dataframe.
```c
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
```
This function creates a new dataframe containing the first `nb_rows` rows from the original dataframe. If `nb_rows` is greater than the number of rows in the original dataframe, it will return all rows.

- **df_tail**: Return a new dataframe with the last N rows of the original dataframe.
```c
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
```
Creates a new dataframe containing the last `nb_rows` rows from the original dataframe. If `nb_rows` is greater than the number of rows in the original dataframe, it will return all rows.

- **df_filter**: Create a new dataframe containing only rows that match a given filter condition.
```c
dataframe_t *df_filter(dataframe_t *dataframe, const char *column, bool (*filter_func)(void *value));
```
Filters the dataframe by applying `filter_func` to each value in the specified column. Returns a new dataframe containing only rows where the filter function returns true.

- **df_sort**: Create a new dataframe with rows sorted based on values in a specified column.
```c
dataframe_t *df_sort(dataframe_t *dataframe, const char *column, bool (*cmp)(void *, void *));
```
Returns a new dataframe with rows sorted according to the comparison function `cmp` applied to values in the specified column.

### Statistical Analysis

- **df_describe**: Print statistical information about numerical columns in the dataframe.
```c
void df_describe(dataframe_t *dataframe);
```
Generates descriptive statistics for each numerical column in the dataframe, including count, mean, standard deviation, minimum, and maximum values.

## 📊 DataFrame Structure

The library uses the following core data structure:

```c
typedef enum {
    INT,
    FLOAT,
    STRING,
    UINT,
} column_type_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
    char separator;
} dataframe_t;
```

## 🛠️ Development

### Code Style

The project follows the EPITECH coding style.

### Contributing

Contributions are welcome! Feel free to submit issues or pull requests to help improve the library.

## 👥 Authors

- Gabriel Decloquement
- Florent Dujardin--Duribreux

Feel free to contribute to this project by submitting issues or pull requests!