A minimal reproducible example for a problem with deleting `QObject`-inherited objects from a list returned from an API object to JS script.

Run a program and press evaluate button on a toolbar. This will create a `QQmlEngine` and evaluate a script which simply creates a single object and a list of objects. Engine is deleted on exit from evaluation.

According to an output I have on my machine:


```
Object created QUuid("{24dace76-d82a-4bac-8a02-ed85720a75a2}") "single"
Object created QUuid("{c017b9cf-736c-48a9-948c-2bd91a2f306d}") "list"
Object created QUuid("{cba4c5c0-fc0f-4c6c-ad6a-cbbc18aaf8a5}") "list"
Object created QUuid("{9c18118a-1eb2-4a18-a7d4-32af3ac86224}") "list"
Object created QUuid("{2ebfed8d-34a8-4677-ad94-3284a98da027}") "list"
Object created QUuid("{76306d43-3f2e-44f9-944c-bb5054891df9}") "list"
ok
Object destroyed QUuid("{24dace76-d82a-4bac-8a02-ed85720a75a2}") "single"
```

objects that is returned as a pointer is deleted properly, while objects contained in a list are never deleted which leads to a memory leak