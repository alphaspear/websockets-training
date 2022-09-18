# Employee Management Server

Employee needs to have fields like id, name, department, projectID.

## ReSTful API {Representational State Transfer}

```
CRUD => {Create, Read, Update, Destroy}

HTTP Methods => {GET, POST, PUT, DELETE, PATCH, OPTIONS, ...}
```

## JSON API

```
CRUD         Action               HTTP Method             URI                   Req body                Res body
---------------------------------------------------------------------------------------------------------------------
Read         Index                GET                   /employees                -                     [{...}, ...]
Read         Show                 GET                   /employees/{id}           -                       {...}
Create       Create               POST                  /employees               {...}                   {id: , ...}
Update       Update               PUT                   /employees/{id}          {...}                    {...}
Update       Update               PATCH                 /employees/{id}          {selected attrs}         {...}
Destroy      Destroy              DELETE                /employees/{id}           -                       - / {...}
```

P.S. A similar [Go application](https://github.com/AgarwalConsulting/emp-server-202208)
