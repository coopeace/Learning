### Definition

> std::filesystem is a C++17 library used for handling files, directories, and paths in a portable and safe way.

> [!TLDR]
> std::filesystem is used to create, delete, traverse, and manage files, directories, and paths efficiently in modern C++.

## Main Uses

+ File & Directory Creation/Deletion
   - create_directory() → creates folder
   - remove() → deletes file/folder
+ Directory Traversal
  - directory_iterator → iterate files in a folder
  - recursive_directory_iterator → traverse subfolders
+ File Information
  - file_size() → returns size
  - last_write_time() → last modified time
+ Copy & Rename
  - copy() → copy files
  - rename() → rename/move files
+ Path Handling (Important)
  - path class helps manage file paths
  - filename() → gets file name
  - extension() → gets file extension
+ File Type Checking
  - is_regular_file()
  - is_directory()
+ Current Directory
  - current_path() → gets working directory

> [!SUMMARY]  
> Safer than manual file handling,Platform independent,Reduces string manipulation errors
