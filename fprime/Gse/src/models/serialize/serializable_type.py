'''
Created on Dec 18, 2014

@author: tcanham

'''
import struct
from type_exceptions import *
import type_base
import u32_type
import string_type
import enum_type

@type_base.serialize
@type_base.deserialize
class SerializableType(type_base.BaseType):
    """
    Representation of the Serializable type (comparable to the ANY type)

    The serializable type is a container for other instances of
    BaseType, including itself.

    @param param: typename = "SomeTypeName" string
    To preserve member order, the member argument is a list of members and their types:
    @param param: mem_list = [ ("member",<ref to BaseType>), ... ]
    """
    def __init__(self, typename, mem_list = None):
        """
        Constructor
        """

        if not type(typename) == type(str()):
            raise TypeMismatchException(type(str()),type(typename))

        self.__typename = typename
        setattr(self, "mem_list", None)
        self.__mem_list = mem_list

        if mem_list == None:
            return;

        if not type(mem_list) == type(list()):
            raise TypeMismatchException(type(list()),type(mem_list))

        # scan the list to see if it has the correct types
        for (memberName,memberVal,format_string) in mem_list:
            # member name should be a string
            if not type(memberName) == type(str()):
                raise TypeMismatchException(type(str()),type(memberName))
            # member value should be a derived class of TypeBase
            if not issubclass(type(memberVal), type_base.BaseType):
                raise TypeMismatchException(type(type_base.BaseType),type(memberVal))
            # format string should be string
            if not type(format_string) == type(str()):
                raise TypeMismatchException(type(str()),type(format_string))

    @property
    def mem_list(self):
        return self.__mem_list


    @mem_list.setter
    def mem_list(self, ml):
        """
        @todo: add arg type checking
        """
        self.__mem_list = ml


    def serialize(self):
        if self.mem_list == None:
            raise NotInitializedException(type(self))

        # iterate through members and serialize each one
        serStream = ""
        for (memberName, memberVal, format_string) in self.mem_list:
            serStream += memberVal.serialize()

        return serStream


    def deserialize(self, data, offset):
        self.__val = []
        for (memberName, memberVal, format_string) in self.mem_list:
            memberVal.deserialize(data, offset)
            self.__val.append(memberVal.val)
            offset += memberVal.getSize()

    @property
    def val(self):
        return self.__val

    def getSize(self):
        size = 0
        for (memberName, memberVal, format_string) in self.mem_list:
            size += memberVal.getSize()
        return size;

if __name__ == '__main__':
    print "Serializable"
    try:
        i32Mem    = u32_type.U32Type(1000000)
        stringMem = string_type.StringType("something to say")
        members   = { "MEMB1":0 , "MEMB2":6, "MEMB3":9 }
        enumMem   = enum_type.EnumType("SomeEnum",members,"MEMB3")
        #print enumMem.val

        memList = [ ("mem1",i32Mem),("mem2",stringMem),("mem3",enumMem)]

        serType = SerializableType("ASerType", memList)

        print "Value: %s" % repr(memList)
        buff = serType.serialize()
        type_base.showBytes(buff)
        serType2 = SerializableType("ASerType",memList)
        serType2.deserialize(buff, len(buff))
        print "Deserialized: %s" % repr(serType2.mem_list)
    except TypeException as e:
        print "Exception: %s" % e.getMsg()
