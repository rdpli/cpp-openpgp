// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

package ch.protonmail.android.utils.nativelib;

import java.util.concurrent.atomic.AtomicBoolean;
import javax.annotation.CheckForNull;
import javax.annotation.Nonnull;

public abstract class IUrl {
    @Nonnull
    public abstract String getValue();

    @Nonnull
    public abstract String getType();

    @CheckForNull
    public static IUrl createInstance(@Nonnull String type, @Nonnull String value)
    {
        return CppProxy.createInstance(type,
                                       value);
    }

    private static final class CppProxy extends IUrl
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        @Override
        public String getValue()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getValue(this.nativeRef);
        }
        private native String native_getValue(long _nativeRef);

        @Override
        public String getType()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getType(this.nativeRef);
        }
        private native String native_getType(long _nativeRef);

        @CheckForNull
        public static native IUrl createInstance(@Nonnull String type, @Nonnull String value);
    }
}
