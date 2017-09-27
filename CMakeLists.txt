cmake_minimum_required(VERSION 3.8)
project(Pascal)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Pascal.cpp Pascal.h
        wci/backend/BackendFactory.h
        wci/backend/BackendFactory.cpp
        wci/backend/Backend.h
        wci/backend/Backend.cpp

        wci/backend/interpreter/Executor.h
        wci/backend/interpreter/Executor.cpp
        wci/backend/interpreter/RuntimeError.cpp
        wci/backend/interpreter/RuntimeError.h
        wci/backend/interpreter/RuntimeErrorHandler.cpp
        wci/backend/interpreter/RuntimeErrorHandler.h

        wci/backend/interpreter/executors/AssignmentExecutor.cpp
        wci/backend/interpreter/executors/AssignmentExecutor.h
        wci/backend/interpreter/executors/CompoundExecutor.cpp
        wci/backend/interpreter/executors/CompoundExecutor.h
        wci/backend/interpreter/executors/ExpressionExecutor.cpp
        wci/backend/interpreter/executors/ExpressionExecutor.h
        wci/backend/interpreter/executors/IfExecutor.cpp
        wci/backend/interpreter/executors/IfExecutor.h
        wci/backend/interpreter/executors/LoopExecutor.cpp
        wci/backend/interpreter/executors/LoopExecutor.h
        wci/backend/interpreter/executors/SelectExecutor.cpp
        wci/backend/interpreter/executors/SelectExecutor.h
        wci/backend/interpreter/executors/StatementExecutor.cpp
        wci/backend/interpreter/executors/StatementExecutor.h

        wci/backend/compiler/CodeGenerator.cpp
        wci/backend/compiler/CodeGenerator.h


        wci/frontend/FrontendFactory.cpp
        wci/frontend/Parser.cpp
        wci/frontend/Scanner.cpp
        wci/frontend/Token.cpp
        wci/frontend/Source.cpp

        wci/frontend/pascal/PascalParserTD.cpp
        wci/frontend/pascal/PascalScanner.cpp
        wci/frontend/pascal/PascalError.cpp
        wci/frontend/pascal/PascalErrorHandler.cpp
        wci/frontend/pascal/PascalToken.cpp
        wci/frontend/pascal/tokens/PascalErrorToken.cpp
        wci/frontend/pascal/tokens/PascalNumberToken.cpp
        wci/frontend/pascal/tokens/PascalSpecialSymbolToken.cpp
        wci/frontend/pascal/tokens/PascalStringToken.cpp
        wci/frontend/pascal/tokens/PascalWordToken.cpp

        wci/frontend/FrontendFactory.h
        wci/frontend/Parser.h
        wci/frontend/Scanner.h
        wci/frontend/Token.h
        wci/frontend/Source.h
        wci/frontend/pascal/PascalParserTD.h
        wci/frontend/pascal/PascalScanner.h
        wci/frontend/pascal/PascalError.h
        wci/frontend/pascal/PascalErrorHandler.h
        wci/frontend/pascal/PascalToken.h
        wci/frontend/pascal/tokens/PascalErrorToken.h
        wci/frontend/pascal/tokens/PascalNumberToken.h
        wci/frontend/pascal/tokens/PascalSpecialSymbolToken.h
        wci/frontend/pascal/tokens/PascalStringToken.h
        wci/frontend/pascal/tokens/PascalWordToken.h

        wci/intermediate/icodeimpl/ICodeImpl.cpp
        wci/intermediate/icodeimpl/ICodeImpl.h
        wci/intermediate/icodeimpl/ICodeNodeImpl.cpp
        wci/intermediate/icodeimpl/ICodeNodeImpl.h

        wci/intermediate/symtabimpl/SymTabEntryImpl.cpp
        wci/intermediate/symtabimpl/SymTabEntryImpl.h
        wci/intermediate/symtabimpl/SymTabImpl.cpp
        wci/intermediate/symtabimpl/SymTabImpl.h
        wci/intermediate/symtabimpl/SymTabStackImpl.cpp
        wci/intermediate/symtabimpl/SymTabStackImpl.h

        wci/intermediate/ICode.h
        wci/intermediate/ICodeFactory.cpp
        wci/intermediate/ICodeFactory.h
        wci/intermediate/ICodeNode.h
        wci/intermediate/SymTab.h
        wci/intermediate/SymTabEntry.h
        wci/intermediate/SymTabFactory.cpp
        wci/intermediate/SymTabFactory.h
        wci/intermediate/SymTabStack.h

        wci/frontend/pascal/parsers/AssignmentStatementParser.cpp
        wci/frontend/pascal/parsers/AssignmentStatementParser.h
        wci/frontend/pascal/parsers/CaseStatementParser.cpp
        wci/frontend/pascal/parsers/CaseStatementParser.h
        wci/frontend/pascal/parsers/CompoundStatementParser.cpp
        wci/frontend/pascal/parsers/CompoundStatementParser.h
        wci/frontend/pascal/parsers/ExpressionParser.cpp
        wci/frontend/pascal/parsers/ExpressionParser.h
        wci/frontend/pascal/parsers/ForStatementParser.cpp
        wci/frontend/pascal/parsers/ForStatementParser.h
        wci/frontend/pascal/parsers/IfStatementParser.cpp
        wci/frontend/pascal/parsers/IfStatementParser.h
        wci/frontend/pascal/parsers/RepeatStatementParser.cpp
        wci/frontend/pascal/parsers/RepeatStatementParser.h
        wci/frontend/pascal/parsers/StatementParser.cpp
        wci/frontend/pascal/parsers/StatementParser.h
        wci/frontend/pascal/parsers/WhenStatementParser.cpp
        wci/frontend/pascal/parsers/WhenStatementParser.h
        wci/frontend/pascal/parsers/WhileStatementParser.cpp
        wci/frontend/pascal/parsers/WhileStatementParser.h

        wci/message/Message.cpp
        wci/message/Message.h
        wci/message/MessageHandler.cpp
        wci/message/MessageHandler.h
        wci/message/MessageListener.h
        wci/message/MessageProducer.h

        wci/util/CrossReferencer.cpp
        wci/util/CrossReferencer.h
        wci/util/ParseTreePrinter.cpp
        wci/util/ParseTreePrinter.h

        wci/DataValue.h)
add_executable(Pascal ${SOURCE_FILES})
